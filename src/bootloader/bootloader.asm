[org 0x7c00]
KERNEL_OFFSET equ 0x1000

mov [BOOT_DRIVE], dl
mov bp, 0x9000
mov sp, bp
mov bx, RMMSG
call print
call nline
call LOAD_KERNEL
call swto_pm
jmp $

%include "include/bootloader_print.asm"
%include "include/bootloader_hexprint.asm"
%include "include/bootloader_disk.asm"
%include "include/32bgdt.asm"
%include "include/32bprint.asm"
%include "include/32bs.asm"

[bits 16]
LOAD_KERNEL:
	mov bx, KLMSG
	call print
	call nline
	mov bx, KERNEL_OFFSET
	mov dh, 2
	mov dl, [BOOT_DRIVE]
	call load_disk
	ret

[bits 32]
BEGIN_PM:
	mov ebx, PMMSG
	call print_spm
	call KERNEL_OFFSET
	jmp $

BOOT_DRIVE db 0
RMMSG db "[AmpereOS]: Loading Real Mode", 0
PMMSG db "[AmpereOS]: Loading Protected Mode", 0
KLMSG db "[AmpereOS]: Loading Kernel", 0

times 510-($-$$) db 0
dw 0xaa55
