savedcmd_bootstrap/vmmblob.o := gcc-13 -Wp,-MMD,bootstrap/.vmmblob.o.d -nostdinc -I/usr/src/linux-headers-6.17.0-14-generic/arch/x86/include -I/usr/src/linux-headers-6.17.0-14-generic/arch/x86/include/generated -I/usr/src/linux-headers-6.17.0-14-generic/include -I/usr/src/linux-headers-6.17.0-14-generic/include -I/usr/src/linux-headers-6.17.0-14-generic/arch/x86/include/uapi -I/usr/src/linux-headers-6.17.0-14-generic/arch/x86/include/generated/uapi -I/usr/src/linux-headers-6.17.0-14-generic/include/uapi -I/usr/src/linux-headers-6.17.0-14-generic/include/generated/uapi -include /usr/src/linux-headers-6.17.0-14-generic/include/linux/compiler-version.h -include /usr/src/linux-headers-6.17.0-14-generic/include/linux/kconfig.h -I/usr/src/linux-headers-6.17.0-14-generic/ubuntu/include -include /usr/src/linux-headers-6.17.0-14-generic/include/linux/compiler_types.h -D__KERNEL__ -std=gnu11 -fshort-wchar -funsigned-char -fno-common -fno-PIE -fno-strict-aliasing -mno-sse -mno-mmx -mno-sse2 -mno-3dnow -mno-avx -mno-sse4a -fcf-protection=none -m64 -falign-jumps=1 -falign-loops=1 -mno-80387 -mno-fp-ret-in-387 -mpreferred-stack-boundary=3 -mskip-rax-setup -march=x86-64 -mtune=generic -mno-red-zone -mcmodel=kernel -mstack-protector-guard-reg=gs -mstack-protector-guard-symbol=__ref_stack_chk_guard -Wno-sign-compare -fno-asynchronous-unwind-tables -mindirect-branch=thunk-extern -mindirect-branch-register -mindirect-branch-cs-prefix -mfunction-return=thunk-extern -fno-jump-tables -mharden-sls=all -fpatchable-function-entry=16,16 -fno-delete-null-pointer-checks -O2 -fno-allow-store-data-races -fstack-protector-strong -fno-omit-frame-pointer -fno-optimize-sibling-calls -ftrivial-auto-var-init=zero -fno-stack-clash-protection -fzero-call-used-regs=used-gpr -pg -mrecord-mcount -mfentry -DCC_USING_FENTRY -falign-functions=16 -fstrict-flex-arrays=3 -fno-strict-overflow -fno-stack-check -fconserve-stack -fno-builtin-wcslen -Wall -Wextra -Wundef -Werror=implicit-function-declaration -Werror=implicit-int -Werror=return-type -Werror=strict-prototypes -Wno-format-security -Wno-trigraphs -Wno-frame-address -Wno-address-of-packed-member -Wmissing-declarations -Wmissing-prototypes -Wframe-larger-than=1024 -Wno-main -Wno-dangling-pointer -Wvla-larger-than=1 -Wno-pointer-sign -Wcast-function-type -Wno-array-bounds -Wno-stringop-overflow -Wno-alloc-size-larger-than -Wimplicit-fallthrough=5 -Werror=date-time -Werror=incompatible-pointer-types -Werror=designated-init -Wenum-conversion -Wunused -Wno-unused-but-set-variable -Wno-unused-const-variable -Wno-packed-not-aligned -Wno-format-overflow -Wno-format-truncation -Wno-stringop-truncation -Wno-override-init -Wno-missing-field-initializers -Wno-type-limits -Wno-shift-negative-value -Wno-maybe-uninitialized -Wno-sign-compare -Wno-unused-parameter -g -gdwarf-5 -Wall -Wstrict-prototypes -DVMW_USING_KBUILD -DVMMON -DVMCORE -I/home/user/Downloads/vmware-modules-fix/vmmon-only/./include -I/home/user/Downloads/vmware-modules-fix/vmmon-only/./include/x86 -I/home/user/Downloads/vmware-modules-fix/vmmon-only/./common -I/home/user/Downloads/vmware-modules-fix/vmmon-only/./linux  -fsanitize=bounds-strict -fsanitize=shift -fsanitize=bool -fsanitize=enum    -DMODULE  -DKBUILD_BASENAME='"vmmblob"' -DKBUILD_MODNAME='"vmmon"' -D__KBUILD_MODNAME=kmod_vmmon -c -o bootstrap/vmmblob.o bootstrap/vmmblob.c   ; /usr/src/linux-headers-6.17.0-14-generic/tools/objtool/objtool --hacks=jump_label --hacks=noinstr --hacks=skylake --retpoline --rethunk --sls --stackval --static-call --uaccess --prefix=16 --Werror   --module bootstrap/vmmblob.o

source_bootstrap/vmmblob.o := bootstrap/vmmblob.c

deps_bootstrap/vmmblob.o := \
  /usr/src/linux-headers-6.17.0-14-generic/include/linux/compiler-version.h \
    $(wildcard include/config/CC_VERSION_TEXT) \
  /usr/src/linux-headers-6.17.0-14-generic/include/linux/kconfig.h \
    $(wildcard include/config/CPU_BIG_ENDIAN) \
    $(wildcard include/config/BOOGER) \
    $(wildcard include/config/FOO) \
  /usr/src/linux-headers-6.17.0-14-generic/include/linux/compiler_types.h \
    $(wildcard include/config/DEBUG_INFO_BTF) \
    $(wildcard include/config/PAHOLE_HAS_BTF_TAG) \
    $(wildcard include/config/FUNCTION_ALIGNMENT) \
    $(wildcard include/config/CC_HAS_SANE_FUNCTION_ALIGNMENT) \
    $(wildcard include/config/X86_64) \
    $(wildcard include/config/ARM64) \
    $(wildcard include/config/LD_DEAD_CODE_DATA_ELIMINATION) \
    $(wildcard include/config/LTO_CLANG) \
    $(wildcard include/config/HAVE_ARCH_COMPILER_H) \
    $(wildcard include/config/CC_HAS_COUNTED_BY) \
    $(wildcard include/config/CC_HAS_MULTIDIMENSIONAL_NONSTRING) \
    $(wildcard include/config/UBSAN_INTEGER_WRAP) \
    $(wildcard include/config/CC_HAS_ASM_INLINE) \
  /usr/src/linux-headers-6.17.0-14-generic/include/linux/compiler_attributes.h \
  /usr/src/linux-headers-6.17.0-14-generic/include/linux/compiler-gcc.h \
    $(wildcard include/config/MITIGATION_RETPOLINE) \
    $(wildcard include/config/ARCH_USE_BUILTIN_BSWAP) \
    $(wildcard include/config/SHADOW_CALL_STACK) \
    $(wildcard include/config/KCOV) \
    $(wildcard include/config/CC_HAS_TYPEOF_UNQUAL) \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/driver-config.h \
    $(wildcard include/config/MODULES) \
    $(wildcard include/config/SMP) \
    $(wildcard include/config/MODVERSIONS) \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/includeCheck.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/compat_version.h \
  /usr/src/linux-headers-6.17.0-14-generic/include/generated/uapi/linux/version.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/compat_autoconf.h \
  /usr/src/linux-headers-6.17.0-14-generic/include/linux/types.h \
    $(wildcard include/config/HAVE_UID16) \
    $(wildcard include/config/UID16) \
    $(wildcard include/config/ARCH_DMA_ADDR_T_64BIT) \
    $(wildcard include/config/PHYS_ADDR_T_64BIT) \
    $(wildcard include/config/64BIT) \
    $(wildcard include/config/ARCH_32BIT_USTAT_F_TINODE) \
  /usr/src/linux-headers-6.17.0-14-generic/include/uapi/linux/types.h \
  /usr/src/linux-headers-6.17.0-14-generic/arch/x86/include/generated/uapi/asm/types.h \
  /usr/src/linux-headers-6.17.0-14-generic/include/uapi/asm-generic/types.h \
  /usr/src/linux-headers-6.17.0-14-generic/include/asm-generic/int-ll64.h \
  /usr/src/linux-headers-6.17.0-14-generic/include/uapi/asm-generic/int-ll64.h \
  /usr/src/linux-headers-6.17.0-14-generic/arch/x86/include/uapi/asm/bitsperlong.h \
  /usr/src/linux-headers-6.17.0-14-generic/include/asm-generic/bitsperlong.h \
  /usr/src/linux-headers-6.17.0-14-generic/include/uapi/asm-generic/bitsperlong.h \
  /usr/src/linux-headers-6.17.0-14-generic/include/uapi/linux/posix_types.h \
  /usr/src/linux-headers-6.17.0-14-generic/include/linux/stddef.h \
  /usr/src/linux-headers-6.17.0-14-generic/include/uapi/linux/stddef.h \
  /usr/src/linux-headers-6.17.0-14-generic/arch/x86/include/asm/posix_types.h \
    $(wildcard include/config/X86_32) \
  /usr/src/linux-headers-6.17.0-14-generic/arch/x86/include/uapi/asm/posix_types_64.h \
  /usr/src/linux-headers-6.17.0-14-generic/include/uapi/asm-generic/posix_types.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/vm_assert.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/vm_basic_types.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./common/hostif.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./common/vmx86.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/x86apic.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/x86msr.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/community_source.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/modulecall.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/cpu_types.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/vm_basic_defs.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/x86/cpu_types_arch.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/address_defs.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/x86segdescrs.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/vm_pagetable.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/ptsc.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/rateconv.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/vm_basic_asm.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/vm_basic_asm_x86_common.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/vm_basic_asm_x86_64.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/vm_atomic.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/versioned_atomic.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/vm_atomic_acqrel.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/vm_atomic_relaxed.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/vcpuid.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/vcpuset.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/vcpuset_types.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/contextinfo.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/x86desc.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/mon_assert.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/uccost.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/uccostTable.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/iocontrols.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/overheadmem_types.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/pageLock_defs.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/sharedAreaType.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./common/apic.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/sharedAreaVmmon.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/statVarsVmmon.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./common/hostifMem.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./common/hostifGlobalLock.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/vmmblob.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/mon_constants.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/monLoader.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/x86paging_64.h \
  /home/user/Downloads/vmware-modules-fix/vmmon-only/./include/x86paging_common.h \

bootstrap/vmmblob.o: $(deps_bootstrap/vmmblob.o)

$(deps_bootstrap/vmmblob.o):

bootstrap/vmmblob.o: $(wildcard /usr/src/linux-headers-6.17.0-14-generic/tools/objtool/objtool)
