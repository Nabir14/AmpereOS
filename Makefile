all: compile run
compile:
	nasm -f bin ./src/bootloader/bootloader.asm -o bootloader.bin
	nasm ./src/kernel/kernel.asm -f elf -o kernel.o
	nasm ./src/kernel/kernel_ep.asm -f elf -o kernel_ep.o
	cat bootlader.bin kernel.bin > ./images/ampereos-dev.bin
run:
	qemu-system-i386 -fda images/amepereos-dev.bin
