savedcmd_vmmon.o := ld -m elf_x86_64 -z noexecstack --no-warn-rwx-segments   -r -o vmmon.o @vmmon.mod 
