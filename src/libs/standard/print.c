#include "print.h"
#include "../libc/string.h"
#include "../extras/vga.h"

void print(const pSTRING string, BYTE text_color, BYTE bg_color)
{
	BYTE* VGA = (BYTE*)VGA_TEXT_ADDR;

	for(WORD i = 0; i < pstring_len(string); i++)
	{
		VGA[i * 2] = string[i];
		VGA[i * 2 + 1] = (bg_color & 0x0F) << 4 | (text_color & 0x0F);
	}
}

void print_at_offset(const pSTRING string, BYTE text_color, BYTE bg_color, WORD col, WORD row)
{
	BYTE* VGA = (BYTE*)VGA_TEXT_ADDR;

	for(WORD i = 0; i < pstring_len(string); i++)
	{
		WORD offset = (row * 80 + (col + i)) * 2;
		VGA[offset] = string[i];
		VGA[offset + 1] = (bg_color & 0x0F) << 4 | (text_color & 0x0F);
	}

}
