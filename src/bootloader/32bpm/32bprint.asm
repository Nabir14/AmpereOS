[bits 32]

VIDEO_MEMORY equ 0xb8000
BYTE_COLOR equ 0x0f

print_spm:
	pusha
	mov edx, VIDEO_MEMORY
print_spm_loop:
	mov al, [ebx]
	mov ah, BYTE_COLOR
	cmp al, 0
	je print_spm_done
	mov [edx], ax
	add ebx, 1
	add edx, 2
	jmp print_spm_loop
print_spm_done:
	popa
	ret
