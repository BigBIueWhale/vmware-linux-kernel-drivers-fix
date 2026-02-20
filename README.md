# VMware Workstation Pro 17.6.4 — Kernel 6.17 Module Fix

## The Problem

VMware Workstation Pro 17.6.4 (build 24832109) fails to start on Ubuntu 24.04.4 LTS
running Linux kernel `6.17.0-14-generic` (HWE kernel). On launch, it shows:

```
Unable to install all modules. See log /tmp/vmware-user/vmware-194052.log for details. (Exit code 1)
```

Both the `vmmon` (Virtual Machine Monitor) and `vmnet` (Virtual Network) kernel modules
fail to compile against kernel 6.17. VMware's internal module builder (`vmware-modconfig`)
extracts the module source from `/usr/lib/vmware/modules/source/vmmon.tar` and
`/usr/lib/vmware/modules/source/vmnet.tar` into a temp directory under `/tmp/modconfig-*/`,
then attempts to compile them — and fails.

## Root Causes (4 separate issues)

### Issue 1: `EXTRA_CFLAGS` dropped from kernel build system

**Affected:** Both `vmmon` and `vmnet`
**Files:** `vmmon-only/Makefile.kernel`, `vmnet-only/Makefile.kernel`
**Symptom:** `fatal error: driver-config.h: No such file or directory` (and many other missing headers)

Starting with kernel 6.17, the kbuild system (`scripts/Makefile.lib`) no longer reads the
`EXTRA_CFLAGS` variable. It was replaced by `ccflags-y`. VMware's Makefiles use
`EXTRA_CFLAGS` to pass include paths like `-I$(SRCROOT)/include`, so when the kernel
build system ignores it, the compiler can't find any of VMware's internal headers
(`driver-config.h`, `vm_basic_types.h`, `vm_basic_defs.h`, `includeCheck.h`, etc.).

The actual kbuild line that constructs compiler flags is in
`/usr/src/linux-headers-6.17.0-14-generic/scripts/Makefile.lib` lines 26-29:

```makefile
_c_flags       = $(filter-out $(CFLAGS_REMOVE_$(target-stem).o), \
                     $(filter-out $(ccflags-remove-y), \
                         $(KBUILD_CPPFLAGS) $(KBUILD_CFLAGS) $(ccflags-y)) \
                     $(CFLAGS_$(target-stem).o))
```

No mention of `EXTRA_CFLAGS` anywhere.

**Fix applied:** Changed `EXTRA_CFLAGS` to `ccflags-y` in both Makefile.kernel files.

### Issue 2: `del_timer_sync()` removed from kernel API

**Affected:** `vmmon`
**Files:** `vmmon-only/linux/driver.c` (line 349), `vmmon-only/linux/hostif.c` (line 1998)
**Symptom:** `error: implicit declaration of function 'del_timer_sync'`

Kernel 6.17 removed the `del_timer_sync()` function. The replacement is
`timer_delete_sync()` which has the same signature and semantics — it's a
straightforward rename by the kernel developers.

- `driver.c` line 349: called during module unload in `LinuxDriverExit()`
- `hostif.c` line 1998: called in `HostIF_CleanupUptime()`

**Fix applied:** Replaced all `del_timer_sync` calls with `timer_delete_sync`.

### Issue 3: `rdmsrl_safe()` removed from kernel API

**Affected:** `vmmon`
**File:** `vmmon-only/linux/hostif.c` (line 3413)
**Symptom:** `error: implicit declaration of function 'rdmsrl_safe'; did you mean 'rdmsrq_safe'?`

Kernel 6.17 renamed `rdmsrl_safe()` to `rdmsrq_safe()`. Same signature, same behavior —
reads a Model-Specific Register (MSR) with error handling. The rename is part of the
kernel's ongoing cleanup of the x86 MSR access API. The new function is defined in
`/usr/src/linux-hwe-6.17-headers-6.17.0-14/arch/x86/include/asm/msr.h` line 218.

**Fix applied:** Replaced `rdmsrl_safe` with `rdmsrq_safe`.

### Issue 4: objtool rejects `vmmon` phystrack.o code and `vmnet` userif.o code

**Affected:** Both `vmmon` and `vmnet`

#### vmmon — phystrack.o

**File:** `vmmon-only/common/phystrack.c`
**Symptom:** `objtool: PhysTrack_Add() falls through to next function PhysTrack_Remove()`

Kernel 6.17's `objtool` (object file validation tool) performs stricter control flow
analysis. It believes `PhysTrack_Add()` can fall through into `PhysTrack_Remove()` based
on the generated assembly, even though the C source is correct. This is a false positive
caused by how GCC arranges the code.

**Fix applied:** Added `OBJECT_FILES_NON_STANDARD_common/phystrack.o := y` and
`OBJECT_FILES_NON_STANDARD_common/task.o := y` to `Makefile.kernel` to skip objtool
validation on these files. This is the standard kernel approach for dealing with out-of-tree
code that triggers false objtool warnings.

#### vmnet — userif.o

**File:** `vmnet-only/userif.c` (lines 553-561)
**Symptom:** `objtool: VNetCsumAndCopyToUser+0x31: call to csum_partial_copy_nocheck() with UACCESS enabled`

The original VMware code wraps a `csum_partial_copy_nocheck()` call inside a
`user_access_begin()`/`user_access_end()` block. Kernel 6.17's objtool rejects this
because `csum_partial_copy_nocheck()` should not be called while user memory access
(UACCESS/STAC) is enabled — it's a security concern.

Original code:
```c
if (!user_access_begin(dst, len)) {
    *err = -EFAULT;
    csum = 0;
} else {
    *err = 0;
    csum = csum_partial_copy_nocheck(src, dst, len);
    user_access_end();
}
```

**Fix applied** (from mkubecek/vmware-host-modules, branch `workstation-17.5.1`):
```c
csum = csum_partial(src, len, ~0U);
if (copy_to_user(dst, src, len))
    csum = 0;
*err = (csum == 0) ? -EFAULT : 0;
```

This computes the checksum separately with `csum_partial()`, then copies to userspace
with `copy_to_user()` (which handles UACCESS internally). No manual
`user_access_begin`/`user_access_end` wrapping needed.

## What Was NOT Changed

- No compiler optimization flags were added (`-O3`, `-ffast-math`, etc.)
- No GRUB parameters were modified
- No sysctl/kernel parameters were changed
- No systemd services were created
- No Python scripts, pip packages, or conda environments were installed
- No system tuning of any kind was performed
- The module source comes directly from VMware's own tarballs at
  `/usr/lib/vmware/modules/source/vmmon.tar` and `vmnet.tar` — only the 4 fixes
  described above were applied

## System Information

| Component | Value |
|---|---|
| OS | Ubuntu 24.04.4 LTS (Noble Numbat) |
| Kernel | 6.17.0-14-generic (HWE) |
| VMware Workstation Pro | 17.6.4 (build 24832109) |
| GCC | gcc-13 (Ubuntu 13.3.0-6ubuntu2~24.04.1) 13.3.0 |
| Kernel GCC | x86_64-linux-gnu-gcc-13 (Ubuntu 13.3.0-6ubuntu2~24.04) 13.3.0 |
| Kernel headers | linux-headers-6.17.0-14-generic |
| Date | 2026-02-20 |

## File Layout

```
vmware-modules-fix/
├── README.md                      ← This file
├── vmmon-only/                    ← Extracted from /usr/lib/vmware/modules/source/vmmon.tar
│   ├── Makefile.kernel            ← MODIFIED: EXTRA_CFLAGS → ccflags-y, added objtool exclusions
│   ├── linux/driver.c             ← MODIFIED: del_timer_sync → timer_delete_sync
│   ├── linux/hostif.c             ← MODIFIED: del_timer_sync → timer_delete_sync,
│   │                                          rdmsrl_safe → rdmsrq_safe
│   └── (all other files unchanged)
├── vmnet-only/                    ← Extracted from /usr/lib/vmware/modules/source/vmnet.tar
│   ├── Makefile.kernel            ← MODIFIED: EXTRA_CFLAGS → ccflags-y
│   ├── userif.c                   ← MODIFIED: VNetCsumAndCopyToUser() rewritten
│   └── (all other files unchanged)
├── vmmon.o                        ← Build artifact (copy of vmmon.ko)
└── vmnet.o                        ← Build artifact (copy of vmnet.ko)
```

## How to Install the Compiled Modules

The compiled `.ko` files are at:
- `vmmon-only/vmmon.ko`
- `vmnet-only/vmnet.ko`

Run these commands to install (requires root):

```bash
# Create the module directory if it doesn't exist
sudo mkdir -p /lib/modules/$(uname -r)/misc

# Copy the compiled modules
sudo cp ~/Downloads/vmware-modules-fix/vmmon-only/vmmon.ko /lib/modules/$(uname -r)/misc/
sudo cp ~/Downloads/vmware-modules-fix/vmnet-only/vmnet.ko /lib/modules/$(uname -r)/misc/

# Rebuild module dependency list
sudo depmod -a

# Load the modules into the running kernel
sudo modprobe vmmon
sudo modprobe vmnet

# Verify they're loaded
lsmod | grep -E "vmmon|vmnet"
```

Expected output from `lsmod`:
```
vmnet                  ...  0
vmmon                  ...  0
```

After this, VMware Workstation Pro should start normally.

## How to Rebuild After a Kernel Update

If the kernel is updated (e.g., from `6.17.0-14` to `6.17.0-15`), the modules must be
recompiled against the new kernel headers. From this directory:

```bash
# Clean old build artifacts
cd ~/Downloads/vmware-modules-fix/vmmon-only && make clean
cd ~/Downloads/vmware-modules-fix/vmnet-only && make clean

# Rebuild (make sure linux-headers-$(uname -r) is installed)
cd ~/Downloads/vmware-modules-fix/vmmon-only && make
cd ~/Downloads/vmware-modules-fix/vmnet-only && make

# Then reinstall as described above
```

If a future kernel changes more APIs, additional fixes may be needed. The fixes in this
directory are specific to kernel 6.17.x.

## Credits

- The `userif.c` fix (Issue 4, vmnet) is from the
  [mkubecek/vmware-host-modules](https://github.com/mkubecek/vmware-host-modules)
  repository, branch `workstation-17.5.1`, commit `665769a`
  ("vmnet: fix csum_and_copy_to_user workaround for kernel >= 5.19").
- All other fixes were derived from kernel 6.17 build errors and the kernel source at
  `/usr/src/linux-hwe-6.17-headers-6.17.0-14/`.
