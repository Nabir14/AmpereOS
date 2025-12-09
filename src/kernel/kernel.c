#include "../libs/standard/print.h"
#include "../libs/extras/vga.h"
#include "../libs/extras/types.h"
#include "../libs/libc/string.h"
#include "../libs/extras/aui.h"

void AMPEREK_CLEAR(BYTE clear_color)
{
	for(int i = 0; i < MAX_COL; i++)
	{
		for(int j = 0; j < MAX_ROW; j++)
		{
			print_at_offset(" ", WHITE, clear_color, i, j);
		}
	}
}

void AMPEREK_INIT()
{
	AMPEREK_CLEAR(BLUE);
	aui_draw_border(LIGHT_BLUE);
	pSTRING title = "AmpereOS";
	pSTRING msg = "No Application Is Running!";
	print_at_offset(title, WHITE, LIGHT_BLUE, aui_get_center_col(pstring_len(title), MAX_COL), 0);
	print_at_offset(msg, WHITE, LIGHT_BLUE, aui_get_center_col(pstring_len(msg), MAX_COL), aui_get_center_row(MAX_ROW));
}

void AMPEREK_MAIN() {
	AMPEREK_INIT();
}
