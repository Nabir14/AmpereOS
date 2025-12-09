#include "aui.h"
#include "vga.h"
#include "../standard/print.h"

void aui_draw_border(BYTE color)
{
	for(WORD i = 0; i < MAX_COL; i++)
	{
		for(WORD j = 0; j < MAX_ROW; j++)
		{
			print_at_offset(" ", WHITE, color, i, 0);
			print_at_offset(" ", WHITE, color, i, MAX_ROW-1);
			print_at_offset(" ", WHITE, color, 0, j);
			print_at_offset(" ", WHITE, color, MAX_COL-1, j);
		}
	}
}

WORD aui_get_center_col(WORD string_len, WORD col_size)
{
	return (WORD)((col_size / 2)-(string_len/2)) - 2;
}

WORD aui_get_center_row(WORD row_size)
{
	return (WORD)((row_size / 2));
}
