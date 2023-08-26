; AmpereOS bootloader
mov ah, 0x0e

mov al, 'A'
int 0x10
mov al, 'm'
int 0x10
mov al, 'p'
int 0x10
mov al, 'e'
int 0x10
mov al, 'r'
int 0x10
mov al, 'e'
int 0x10
mov al, 'O'
int 0x10
mov al, 'S'
int 0x10

jmp $

times 510 - ($-$$) db 0
dw 0xaa55
