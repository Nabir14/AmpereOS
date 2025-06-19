all: compile-bootloader compile-kernel build-image run clean
compile-bootloader:
	nasm -f bin /workspaces/AmpereOS/src/bootloader/bootloader.asm -o /workspaces/AmpereOS/bootloader.bin
compile-kernel:
	./scripts/cross-compiler/bin/i686-elf-gcc -ffreestanding -c ./src/kernel/kernel.c -o kernel.o
	nasm ./src/kernel/kernel_ep.asm -f elf -o kernel_ep.o
	./scripts/cross-compiler/bin/i686-elf-ld -o kernel.bin -Ttext 0x1000 kernel_ep.o kernel.o --oformat binary
build-image:
	cat bootloader.bin kernel.bin > ./os-image/ampereos-dev.bin
run:
	qemu-system-i386 -fda images/amepereos-dev.bin
#clean:
#rm -rf kernel.o kernel_ep.o bootloader.bin kernel.bin