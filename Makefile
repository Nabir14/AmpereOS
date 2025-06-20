all: build-image run
cc-compile-bootloader:
	nasm -f bin /workspaces/AmpereOS/src/bootloader/bootloader.asm -o /workspaces/AmpereOS/bootloader.bin
cc-compile-kernel:
	./scripts/cross-compiler/bin/i686-elf-gcc -ffreestanding -c ./src/kernel/kernel.c -o ./src/kernel.o
	./scripts/cross-compiler/bin/i686-elf-gcc -ffreestanding -c ./src/kernel/drivers/io-ports.c -o ./src/io-ports.o
	./scripts/cross-compiler/bin/i686-elf-gcc -ffreestanding -c ./src/kernel/drivers/io-text.c -o ./src/io-text.o
	nasm ./src/kernel/kernel_ep.asm -f elf -o ./src/kernel_ep.o
	./scripts/cross-compiler/bin/i686-elf-ld -o kernel.bin -Ttext 0x1000 ./src/kernel_ep.o ./src/kernel.o ./src/io-ports.o ./src/io-text.o --oformat binary
build-image:
	cat bootloader.bin kernel.bin > ./os-image/ampereos-dev.bin
run:
	qemu-system-i386 -fda os-image/ampereos-dev.bin
clean:
	rm -rf ./src/kernel.o ./src/kernel_ep.o ./src/ports.o ./src/io-text.o
