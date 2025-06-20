#include "drivers/io-ports.h"
#include "drivers/io-text.h"

#define OS_AUTHOR "MD Mushfique Farhan Nabir (A.K.A Nabir14)"
#define KERNEL_VERSION 0.2

void AMPEREK_INIT(){
	AMPEREK_TEXT_MODE_CLEAR();
	AMPEREK_PRINT("AmpereOS\n", 0, 0, WHITE_TEXT);
	AMPEREK_PRINT((char)KERNEL_VERSION, 0, 1, RED_TEXT);
}

void AMPEREK_MAIN(){
	AMPEREK_INIT();
}
