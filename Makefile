all: clean cc-compile-bootloader cc-compile-kernel build-image run
cc-compile-bootloader:
	nasm -fbin src/bootloader/bootloader.asm -o bootloader.bin -I src/bootloader/
cc-compile-kernel:
	./scripts/cross-compiler/bin/i386-elf-gcc -ffreestanding -c ./src/kernel/kernel.c -o ./src/kernel.o
	./scripts/cross-compiler/bin/i386-elf-gcc -ffreestanding -c ./src/kernel/drivers/io-ports.c -o ./src/io-ports.o
	./scripts/cross-compiler/bin/i386-elf-gcc -ffreestanding -c ./src/kernel/drivers/io-text.c -o ./src/io-text.o
	./scripts/cross-compiler/bin/i386-elf-gcc -ffreestanding -c ./src/kernel/libc/mem.c -o ./src/mem.o
	nasm ./src/kernel/kernel_ep.asm -f elf -o ./src/kernel_ep.o
	./scripts/cross-compiler/bin/i386-elf-ld -o kernel.bin -Ttext 0x1000 ./src/kernel_ep.o ./src/kernel.o ./src/io-ports.o ./src/io-text.o ./src/mem.o --oformat binary
build-image:
	cat bootloader.bin kernel.bin > ./os-image/ampereos-dev.bin
run:
	qemu-system-i386 -hda os-image/ampereos-dev.bin
clean:
	rm -rf ./src/kernel.o ./src/kernel_ep.o ./src/io-ports.o ./src/io-text.o ./src/mem.o kernel.bin bootloader.bin os-image/ampereos-dev.bin
