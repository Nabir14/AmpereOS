global boot_kernel

extern AMPEREK_LOAD

GRUB_MAGIC_NUMBER equ 0x1BADB002
FLAGS equ 0x0
CHECKSUM equ -(GRUB_MAGIC_NUMBER+FLAGS)

section .text:
align 4
        dd GRUB_MAGIC_NUMBER
        dd FLAGS
        dd CHECKSUM

boot_kernel:
	call AMPEREK_LOAD
