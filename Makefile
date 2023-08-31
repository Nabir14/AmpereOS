.PHONY: all
all: compile disk
compile:
	mkdir -p build
	nasm -fbin src/bootloader/stage1/main.asm -o build/main.bin
disk:
	dd if=/dev/zero of=build/image.img bs=104857 count=128
	bash tool/partition.sh
	sudo mkfs.vfat -F 16 -n "EFI System" build/image.img
	dd if=build/main.bin of=build/image.img conv=notrunc bs=512 count=1

run:
	qemu-system-i386 -hda build/image.img
