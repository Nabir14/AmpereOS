#include "drivers/ports.h"

#define VGA_MEM_ADDR 0xb8000

void AMPEREK_CLEAR_SCREEN(){
	for(int i = 0; i < 80 * 25; i++){
		char* VGA = VGA_MEM_ADDR;
		int OFFSET = i * 2;
		VGA[OFFSET] = ' ';
		VGA[OFFSET+1] = 0x0f;
	}
}
void AMPEREK_MAIN(){
	AMPEREK_CLEAR_SCREEN();
}
