#include "io.h"

void outb(WORD port, BYTE value)
{
	__asm__ __volatile__("out %%al, %%dx" : : "d"(port), "a"(value) :);
}

BYTE inb(WORD port)
{
	BYTE value;
	__asm__ __volatile__("in %%dx, %%al" : "=a"(value) : "d"(port) :);
	return value;
}
