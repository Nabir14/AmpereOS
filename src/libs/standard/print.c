#include "print.h"
#include "../libc/string.h"
#include "../extras/vga.h"
#include "cursor.h"

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
		WORD offset = (get_offset(col, row) + i) * 2;
		VGA[offset] = string[i];
		VGA[offset + 1] = (bg_color & 0x0F) << 4 | (text_color & 0x0F);
	}

}

void print_at_cursor(const pSTRING string, BYTE text_color, BYTE bg_color)
{
	BYTE* VGA = (BYTE*)VGA_TEXT_ADDR;

	WORD offset = get_cursor_offset();
	BYTE col = get_col(offset);
	BYTE row = get_row(offset);

	for(WORD i = 0; i < pstring_len(string); i++)
	{
		VGA[(offset + i) * 2] = string[i];
		VGA[(offset + i) * 2 + 1] = (bg_color & 0x0F) << 4 | (text_color & 0x0F);
	}

	set_cursor_offset(col+pstring_len(string), row);
}

