[org 0x7c00]

	mov bp, 0x9000
	mov sp, bp
	mov bx, RMMSG
	call print
	call swto_pm

	jmp $

%include "function_strings/bootloader_print.asm"
%include "function_strings/bootloader_hexprint.asm"
%include "disk/bootloader_disk.asm"
%include "32bpm/32bgdt.asm"
%include "32bpm/32bprint.asm"
%include "32bpm/32bs.asm"

[bits 32]
BEGIN_PM:
	mov ebx, PMMSG
	call print_spm
	jmp $

RMMSG db "Loading..."
PMMSG db "AmpereOS", 0

times 510-($-$$) db 0
dw 0xaa55

