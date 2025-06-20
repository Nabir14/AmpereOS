#include "drivers/io-ports.h"
#include "drivers/io-text.h"

#define OS_AUTHOR "MD Mushfique Farhan Nabir (A.K.A Nabir14)"
#define KERNEL_VERSION 0.2

void AMPEREK_INIT(){
	AMPEREK_TEXT_MODE_CLEAR();
	for(int i = 0; i < 80; i++){
		AMPEREK_PRINT(' ', i, 0, WHITE_SPACE);
	}
	AMPEREK_PRINT("AmpereOS", 40, 12, BLACK_TEXT);
	AMPEREK_PRINT_AT_CURSOR("\n", WHITE_TEXT);
	AMPEREK_PRINT_AT_CURSOR("$>", CYAN_TEXT);
}

void AMPEREK_MAIN(){
	AMPEREK_INIT();
}
