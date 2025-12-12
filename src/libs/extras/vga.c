#include "vga.h"

WORD get_offset(WORD col, WORD row)
{
	return row * MAX_COL + col;
}

BYTE get_col(WORD offset)
{
	return (BYTE) offset % MAX_COL;
}

BYTE get_row(WORD offset)
{
	return (BYTE) offset / MAX_COL;
}
