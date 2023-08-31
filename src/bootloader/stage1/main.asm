[bits 16]
[org 0]

main:
	mov al, 'H'
	mov ah, 0x0e
	int 0x10
	hlt
