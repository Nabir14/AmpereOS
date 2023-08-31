[org 0x7c00]

	mov bp, 0x8000
	mov sp, bp
	mov bx, 0x9000
	mov dh, 2
	call load_disk
	mov dx, [0x9000]
	call print
	call nline

	jmp $

%include "function_strings/bootloader_print.asm"
%include "function_strings/bootloader_hexprint.asm"
%include "disk/bootloader_disk.asm"

times 510 - ($-$$) db 0
dw 0xaa55

times 512 db "AmpereOS", 0
