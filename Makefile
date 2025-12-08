GAS = "cross-compiler/bin/i386-elf-as"
GCC = "cross-compiler/bin/i386-elf-gcc"
LD = "cross-compiler/bin/i386-elf-ld"

all: clean build-kernel build-isofs build-iso run
build-kernel:
	mkdir -p build
	nasm -f elf32 src/grub-boot.asm -o build/grub-boot.o
	nasm -f elf32 src/kernel/kernel_ep.asm -o build/kernel_ep.o
	$(GCC) src/kernel/kernel.c -o build/kernel.o -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
	$(GCC) src/libs/standard/print.c -o build/print.o -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
	$(GCC) src/libs/libc/string.c -o build/string.o -m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector -nostartfiles -nodefaultlibs -Wall -Wextra -Werror -c
	$(LD) -T src/link.ld -melf_i386 build/grub-boot.o build/print.o build/string.o build/kernel.o build/kernel_ep.o -o build/kernel.elf
build-isofs:
	mkdir -p build/ampere-isofs/boot/grub
	cat src/grub-cfg.txt > build/ampere-isofs/boot/grub/grub.cfg
	mv build/kernel.elf build/ampere-isofs/boot
build-iso:
	grub2-mkrescue -o build/ampereos.iso build/ampere-isofs
run:
	qemu-system-i386 build/ampereos.iso
clean:
	rm -rf build
