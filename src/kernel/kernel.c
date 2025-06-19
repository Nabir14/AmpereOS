#include "drivers/ports.h"

#define VGA_MEM_ADDR 0xb8000

void main(){
	char* VGA = VGA_MEM_ADDR;
	IO_BYTE_WRITE(0x3d4, 14);
	int CURSOR_POS = IO_BYTE_READ(0x3d5);
	CURSOR_POS <<= 8;
	IO_BYTE_WRITE(0x3d4, 15);
	CURSOR_POS = IO_BYTE_READ(0x3d5);
	int OFFSET = CURSOR_POS * 2;
	VGA[OFFSET] = 'A';
	VGA[OFFSET + 1] = 0x0f;
	clear_screen(VGA);
}

void clear_screen(char* vga){
	for(int i = 0; i < 80 * 25; i++){
		//char* VGA = VGA_MEM_ADDR;
		int OFFSET = i * 2;
		vga[OFFSET] = ' ';
		vga[(OFFSET+1) + 1] = 0x0f;
	}
}
