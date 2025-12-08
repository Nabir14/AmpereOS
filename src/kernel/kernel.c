#include "../libs/standard/print.h"
#include "../libs/extras/vga.h"

void AMPEREK_INIT()
{
	for(int i = 0; i < MAX_COL; i++)
	{
		for(int j = 0; j < MAX_ROW; j++)
		{
			print_at_offset(" ", WHITE, BLUE, i, j);
		}
	}

	print("AmpereOS", WHITE, BLUE);
}

void AMPEREK_MAIN() {
	AMPEREK_INIT();
}
