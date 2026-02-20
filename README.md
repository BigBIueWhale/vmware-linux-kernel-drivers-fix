# VMware Workstation Pro 17.6.4 — Kernel 6.17 Module Fix

## Source / Provenance

**This repository contains VMware's own kernel module source code with 4 minimal fixes
applied for Linux kernel 6.17 compatibility.**

The code in this repository is **not** based on any third-party fork or community
reimplementation. It was extracted directly from the official tarballs that VMware ships
inside VMware Workstation Pro itself:

| Item | Value |
|---|---|
| **vmmon source tarball** | `/usr/lib/vmware/modules/source/vmmon.tar` (1.7 MB) — original copy included in this repo: [`original-vmmon.tar`](original-vmmon.tar) |
| **vmnet source tarball** | `/usr/lib/vmware/modules/source/vmnet.tar` (788 KB) — original copy included in this repo: [`original-vmnet.tar`](original-vmnet.tar) |
| **VMware product** | VMware Workstation Pro 17.6.4 |
| **VMware build number** | 24832109 |
| **VMware installer** | `VMware-Workstation-Full-17.6.4-24832109.x86_64.bundle` |
| **Copyright holder** | Broadcom Inc. (formerly VMware, Inc.) — all original `.c` and `.h` files carry Broadcom/VMware copyright headers and are licensed under GPLv2 |

### What this means

- **The base code is identical to what VMware's own module builder (`vmware-modconfig`)
  extracts and tries to compile.** When you launch VMware Workstation, it runs
  `vmware-modconfig` which extracts these same tarballs into `/tmp/modconfig-*/` and
  compiles them with `make`. On kernel 6.17, that compilation fails. This repo contains
  the same extracted source, with only the fixes needed to make it compile.

- **No third-party code was used as a base.** The only external reference was a single
  fix borrowed from the [mkubecek/vmware-host-modules](https://github.com/mkubecek/vmware-host-modules)
  community repository (see Issue 4 / vmnet below and the "Third-Party Repos" section).
  That fix was a 3-line code change applied on top of VMware's own source — not a
  wholesale replacement of any file.

- **The tarballs are installed by VMware's own `.bundle` installer.** They exist on any
  system where VMware Workstation Pro 17.6.4 is installed. If you reinstall or update
  VMware, the tarballs at `/usr/lib/vmware/modules/source/` will be replaced with
  whatever the new version ships.

- **Only 5 files were modified** out of the hundreds in the two tarballs. Every other
  file is byte-for-byte identical to what VMware ships. The 5 modified files and the
  exact changes are documented in detail below.

### How to verify provenance yourself

The original unmodified tarballs are included in this repo for exactly this purpose:
- [`original-vmmon.tar`](original-vmmon.tar) — byte-for-byte copy of `/usr/lib/vmware/modules/source/vmmon.tar`
- [`original-vmnet.tar`](original-vmnet.tar) — byte-for-byte copy of `/usr/lib/vmware/modules/source/vmnet.tar`

You can diff against them directly:

```bash
mkdir /tmp/vmware-orig
tar xf original-vmmon.tar -C /tmp/vmware-orig
tar xf original-vmnet.tar -C /tmp/vmware-orig
# Compare (only the 5 fixed files should differ — ignore build artifacts):
diff -rq /tmp/vmware-orig/vmmon-only/ ./vmmon-only/ | grep -v "\.o$\|\.ko$\|\.cmd$\|\.order$\|\.symvers$\|\.mod"
diff -rq /tmp/vmware-orig/vmnet-only/ ./vmnet-only/ | grep -v "\.o$\|\.ko$\|\.cmd$\|\.order$\|\.symvers$\|\.mod"
```

Or, on any machine with VMware Workstation Pro 17.6.4 installed, you can extract from
the system-installed tarballs instead:

```bash
mkdir /tmp/vmware-orig
tar xf /usr/lib/vmware/modules/source/vmmon.tar -C /tmp/vmware-orig
tar xf /usr/lib/vmware/modules/source/vmnet.tar -C /tmp/vmware-orig
diff -rq /tmp/vmware-orig/vmmon-only/ ./vmmon-only/ | grep -v "\.o$\|\.ko$\|\.cmd$\|\.order$\|\.symvers$\|\.mod"
diff -rq /tmp/vmware-orig/vmnet-only/ ./vmnet-only/ | grep -v "\.o$\|\.ko$\|\.cmd$\|\.order$\|\.symvers$\|\.mod"
```

Expected output — only these 5 files differ:
```
Files /tmp/vmware-orig/vmmon-only/Makefile.kernel and ./vmmon-only/Makefile.kernel differ
Files /tmp/vmware-orig/vmmon-only/linux/driver.c and ./vmmon-only/linux/driver.c differ
Files /tmp/vmware-orig/vmmon-only/linux/hostif.c and ./vmmon-only/linux/hostif.c differ
Files /tmp/vmware-orig/vmnet-only/Makefile.kernel and ./vmnet-only/Makefile.kernel differ
Files /tmp/vmware-orig/vmnet-only/userif.c and ./vmnet-only/userif.c differ
```

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

## Third-Party Repos Evaluated and Rejected

### Hyphaed/vmware-vmmon-vmnet-linux-6.17.x (REJECTED)

Repository: `https://github.com/Hyphaed/vmware-vmmon-vmnet-linux-6.17.x`

This was the first candidate — a dedicated repo specifically for kernel 6.17.x VMware
module patches, with an interactive Python wizard installer. It was cloned to
`~/Downloads/vmware-vmmon-vmnet-linux-6.17.x` and subjected to a full security audit
before being deleted without running anything.

**Why it was rejected — security and scope concerns:**

1. **`pip install` as root:** `detect_hardware.py` and `tune_system.py` auto-install
   Python packages from PyPI (`psutil`, `distro`, `questionary`, `rich`) while running as
   root. A compromised PyPI package would execute arbitrary code with root privileges.
   This is a known supply chain attack vector.

2. **Silent GRUB modification:** `check_and_fix_memory.py` is called automatically by
   the wizard *before the user even sees the welcome screen*. It modifies
   `/etc/default/grub` to remove hugepage parameters and runs `update-grub` without
   asking for confirmation.

3. **Dangerous compiler flags for kernel modules:** The "optimized" mode patches add
   `-O3 -ffast-math -funroll-loops -march=native` to the kernel module Makefiles.
   `-ffast-math` breaks IEEE 754 floating-point compliance and is explicitly discouraged
   for kernel code. `-O3` instead of the kernel-standard `-O2` can expose compiler bugs.

4. **Massive scope beyond module compilation:** The install script (2,847 lines) and its
   supporting Python scripts also: modify GRUB boot parameters (`intel_iommu=on`,
   `iommu=pt`, `transparent_hugepage=madvise`), create systemd services, force the CPU
   governor to "performance" on all cores permanently, change sysctl parameters
   (`vm.swappiness`, network buffers, etc.), change the NVMe I/O scheduler, and install
   system packages — all things completely unrelated to fixing VMware's kernel modules.

5. **Log clearing script included:** `scripts/clear-system-logs.sh` wipes `journalctl`,
   `dmesg`, `/var/log/auth.log`, `/var/log/syslog`, and other logs. Not called by the
   installer, but its inclusion in a "VMware module fix" repo is suspicious.

6. **Git clone fallback as root:** If local patch files aren't found, the install script
   falls back to `git clone` from GitHub while running as root.

7. **Miniforge/conda download:** `setup_python_env.sh` downloads and installs
   Miniforge from GitHub, creates a conda environment, and installs numerous packages
   — again, all as root.

**In short:** The repo is not malware — no backdoors, reverse shells, or data exfiltration
were found — but it is wildly over-engineered and makes aggressive system changes that
have nothing to do with fixing two kernel modules. For a task that requires editing 5 lines
of code across 4 files, a 2,847-line install script with Python wizards and system tuning
is not justified.

### mkubecek/vmware-host-modules (PARTIALLY USED)

Repository: `https://github.com/mkubecek/vmware-host-modules`
Cloned to: `~/Downloads/vmware-host-modules` (still present)

This is the well-known, trusted community repository for VMware host module patches.
It is minimal — just patched C source and Makefiles, no scripts, no wizards.

**Why it was not used directly:**

- The latest branch is `workstation-17.5.1`. There is no branch for VMware Workstation
  17.6.4. The module source for 17.5.1 differs from 17.6.4, so using it directly could
  introduce version mismatches or missing symbols.
- The `workstation-17.5.1` branch does not include fixes for kernel 6.17-specific issues
  (the `EXTRA_CFLAGS` → `ccflags-y` change, `del_timer_sync` removal, `rdmsrl_safe`
  rename). Its latest commit (`2c6d66f`) addresses `-Wmissing-prototypes` but not
  kernel 6.17 API removals.

**What was borrowed:** The `VNetCsumAndCopyToUser()` fix in `userif.c` (Issue 4 above)
was taken from mkubecek's branch `workstation-17.5.1`, commit `665769a`. This specific
fix replaces the `user_access_begin`/`csum_partial_copy_nocheck`/`user_access_end`
pattern with `csum_partial()` + `copy_to_user()`, and is a clean, well-tested solution
that has been in the repo since kernel 5.19 compatibility work.

### Approach Chosen Instead

Rather than using either third-party repo, we extracted VMware's own module source
tarballs from `/usr/lib/vmware/modules/source/vmmon.tar` and `vmnet.tar` (shipped with
VMware Workstation Pro 17.6.4 itself), applied only the 4 minimal fixes needed for
kernel 6.17 compatibility, and compiled directly. This ensures:

- The module source exactly matches VMware 17.6.4 (no version mismatch risk)
- No third-party code is running as root
- No system modifications beyond the two `.ko` files
- Every change is auditable (5 files changed, each change is a 1-3 line edit)

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
├── original-vmmon.tar             ← UNMODIFIED copy of /usr/lib/vmware/modules/source/vmmon.tar
│                                     (VMware Workstation Pro 17.6.4, build 24832109)
├── original-vmnet.tar             ← UNMODIFIED copy of /usr/lib/vmware/modules/source/vmnet.tar
│                                     (VMware Workstation Pro 17.6.4, build 24832109)
├── vmmon-only/                    ← Extracted from vmmon.tar, then patched (3 files modified)
│   ├── Makefile.kernel            ← MODIFIED: EXTRA_CFLAGS → ccflags-y, added objtool exclusions
│   ├── linux/driver.c             ← MODIFIED: del_timer_sync → timer_delete_sync
│   ├── linux/hostif.c             ← MODIFIED: del_timer_sync → timer_delete_sync,
│   │                                          rdmsrl_safe → rdmsrq_safe
│   └── (all other files unchanged from original tarball)
├── vmnet-only/                    ← Extracted from vmnet.tar, then patched (2 files modified)
│   ├── Makefile.kernel            ← MODIFIED: EXTRA_CFLAGS → ccflags-y
│   ├── userif.c                   ← MODIFIED: VNetCsumAndCopyToUser() rewritten
│   └── (all other files unchanged from original tarball)
├── vmmon.o                        ← Build artifact (copy of vmmon.ko)
└── vmnet.o                        ← Build artifact (copy of vmnet.ko)
```

## Persistence, Kernel Updates, and `apt upgrade` Behavior

### Are the installed modules permanent?

Yes. The `.ko` files placed in `/lib/modules/6.17.0-14-generic/misc/` persist across
reboots. VMware's systemd service (`vmware.service`) runs `modprobe vmmon` and
`modprobe vmnet` on boot, which loads them from that directory automatically.

### What happens on `sudo apt upgrade`?

**Scenario 1 — New kernel version installed (e.g., `6.17.0-15-generic`):**
Each kernel version has its own completely separate `/lib/modules/<version>/` tree.
Our modules live in `/lib/modules/6.17.0-14-generic/misc/` and will NOT be copied to the
new kernel's directory. If you boot into the new kernel, VMware will fail again with the
same "Unable to install all modules" error. You would need to rebuild from this directory
(see "How to Rebuild After a Kernel Update" below). The old modules are not deleted —
they just sit unused in the old kernel's directory.

**Scenario 2 — VMware itself is updated:**
VMware Workstation Pro is NOT installed via apt (it was installed from
`/home/user/Downloads/downloaded_vmware_workstation_pro_17/VMware-Workstation-Full-17.6.4-24832109.x86_64.bundle`),
so `apt upgrade` will not touch VMware. If you manually install a newer VMware version
in the future, its installer may replace the source tarballs at
`/usr/lib/vmware/modules/source/vmmon.tar` and `vmnet.tar`, and VMware's `modconfig`
may attempt to rebuild modules on its own. Our installed `.ko` files in
`/lib/modules/*/misc/` would remain, but could be overwritten by VMware's rebuilder.

**Scenario 3 — Nothing kernel-related changes:**
The modules remain installed and loaded. Nothing happens to them.

### Relevant paths on this system

| Path | Description | Exists? |
|---|---|---|
| `/usr/lib/vmware/modules/source/vmmon.tar` | VMware's shipped vmmon source tarball (1.7 MB) | Yes |
| `/usr/lib/vmware/modules/source/vmnet.tar` | VMware's shipped vmnet source tarball (788 KB) | Yes |
| `/lib/modules/6.17.0-14-generic/misc/` | Target directory for compiled modules | No (created during install) |
| `/lib/modules/6.17.0-14-generic/misc/vmmon.ko` | Installed vmmon module | No (created during install) |
| `/lib/modules/6.17.0-14-generic/misc/vmnet.ko` | Installed vmnet module | No (created during install) |
| `/usr/src/linux-headers-6.17.0-14-generic/` | Kernel headers used for compilation | Yes |
| `/usr/src/linux-hwe-6.17-headers-6.17.0-14/` | Shared kernel headers (arch-specific, contains `asm/msr.h`) | Yes |
| `~/Downloads/vmware-modules-fix/` | This directory — patched source and compiled modules | Yes |
| `~/Downloads/vmware-host-modules/` | mkubecek repo clone (used as reference for userif.c fix) | Yes |
| `~/Downloads/downloaded_vmware_workstation_pro_17/` | Original VMware installer bundle | Yes |
| `/home/user/.vmware/config` | VMware user config (does not exist yet) | No |
| `/usr/lib/vmware/settings` | VMware global settings (does not exist) | No |

### Do we need to back up existing modules?

No. There are no existing `vmmon.ko` or `vmnet.ko` files anywhere in
`/lib/modules/6.17.0-14-generic/`. The directory `/lib/modules/6.17.0-14-generic/misc/`
does not even exist yet — it will be created during installation. VMware's `modconfig`
failed to compile the modules (that's the whole problem), so it never produced any `.ko`
files to install. There is nothing to back up.

## How to Install the Compiled Modules

The compiled `.ko` files are at:
- `vmmon-only/vmmon.ko`
- `vmnet-only/vmnet.ko`

**Secure Boot note:** These are unsigned out-of-tree kernel modules. If Secure Boot is
enabled, the kernel will refuse to load them. Check with `mokutil --sb-state`. If Secure
Boot is on, you must either sign the modules with a Machine Owner Key (MOK) or disable
Secure Boot in your UEFI/BIOS settings. On this system, Secure Boot is off (disabled for
the NVIDIA driver), so this is not an issue.

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

After this, you **must** restart the VMware services so the networking daemons
(`vmnetBridge`, `vmnet-natd`) start and the `/dev/vmnet*` device nodes are created.
Without this step, VMs will fail to connect to virtual networks with errors like
*"Could not connect 'Ethernet0' to virtual network '/dev/vmnet8'"*.

```bash
# Restart VMware services (creates /dev/vmnet0, /dev/vmnet1, /dev/vmnet8, starts NAT/DHCP)
sudo systemctl restart vmware

# Verify the vmnet devices were created
ls /dev/vmnet*
```

Expected output from `ls /dev/vmnet*`:
```
/dev/vmnet0  /dev/vmnet1  /dev/vmnet8
```

After this, VMware Workstation Pro should start normally and VM networking should work.

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
