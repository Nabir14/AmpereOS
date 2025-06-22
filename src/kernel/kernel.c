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
	for(int i = 0; i < 128; i++){
		AMPEREK_PRINT_AT_CURSOR("y\n", WHITE_TEXT);
	}
	return;
}
