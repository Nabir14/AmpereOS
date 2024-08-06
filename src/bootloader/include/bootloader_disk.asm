load_disk:
	pusha
	push dx
	mov ah, 0x02
	mov al, dh
	mov cl, 0x02
	mov ch, 0x00
	mov dh, 0x00
	int 0x13
	jc disk_error
	pop dx
	cmp al, dh
	jne sectors_error
	popa
	ret

disk_error:
	mov bx, DISK_ERROR
	call print
	mov dh, ah
	call hexprint
	jmp disk_loop

sectors_error:
	mov bx, SECTORS_ERROR
	call print

disk_loop:
	jmp $

DISK_ERROR: db "[AmpereOS]: Disk load error ", 0
SECTORS_ERROR: db "[AmpereOS]: Sectors error", 0
