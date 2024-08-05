hexprint:
	pusha
	mov cx, 0
hexloop:
	cmp cx, 4
	je end
	mov ax, dx
	and ax, 0x000f
	add al, 0x30
	cmp al, 0x39
	jle getsp
	add al, 7
getsp:
	mov bx, HEX_OUT + 5
	sub bx, cx
	mov [bx], al
	ror dx, 4
	add cx, 1
	jmp hexloop
end:
	mov bx, HEX_OUT
	call print
	popa
	ret
HEX_OUT:
	db '0x0000',0

