#include "drivers/io-ports.h"
#include "drivers/io-text.h"

void AMPEREK_INIT(){
	AMPEREK_TEXT_MODE_CLEAR();
	AMPEREK_PRINT("AmpereOS", 0, 0, WHITE_TEXT);
	AMPEREK_PRINT_AT_CURSOR("\n", WHITE_TEXT);
	AMPEREK_PRINT_AT_CURSOR("[$]:", WHITE_TEXT);
}

void AMPEREK_MAIN(){
	AMPEREK_INIT();
	for(int i = 0; i < 1024; i++){
		AMPEREK_PRINT("y\n", 0, 128, WHITE_TEXT);
	}
}
