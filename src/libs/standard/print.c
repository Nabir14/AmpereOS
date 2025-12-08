#include "print.h"
#include "../libc/string.h"
#include "../extras/vga.h"

void print(const pSTRING string, BYTE color)
{
	BYTE* VGA = (BYTE*)VGA_TEXT_ADDR;

	for(WORD i = 0; i < pstring_len(string); i++)
	{
		VGA[i * 2] = string[i];
		VGA[i * 2 + 1] = color;
	}
}
