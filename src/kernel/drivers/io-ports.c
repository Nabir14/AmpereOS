#include "io-ports.h"

BYTE IO_BYTE_READ(WORD port){
	BYTE res;
	__asm__("in %%dx, %%al": "=a" (res) : "d" (port));
	return res;
}

void IO_BYTE_WRITE(WORD port, BYTE data){
	__asm__("out %%al, %%dx": : "a" (data), "d" (port));
}

WORD IO_WORD_READ(WORD port){
	WORD res;
	__asm__("in %%dx, %%al": "=a" (res) : "d" (port));
	return res;
}

void IO_WORD_WRITE(WORD port, WORD data){
	__asm__("out %%al, %%dx": : "a" (data), "d" (port));
}
