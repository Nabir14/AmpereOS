#include "drivers/io-ports.h"
#include "drivers/io-text.h"

void AMPEREK_MAIN(){
	AMPEREK_TEXT_MODE_CLEAR();
	AMPEREK_PRINT("AmpereOS\n", 0, 0, WHITE_TEXT);
}
