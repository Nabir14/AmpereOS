#include "cursor.h"
#include "../io/io.h"
#include "../extras/vga.h"

void set_cursor_offset(WORD col, WORD row)
{
	unsigned short offset = (unsigned short) get_offset(col, row);
	outb(0x3d4, 0xE);
	outb(0x3d5, (BYTE) ((offset >> 8) & 0xFF));
	outb(0x3d4, 0xF);
	outb(0x3d5, (BYTE) (offset & 0xFF));
}

WORD get_cursor_offset()
{
	WORD offset = 0;
	outb(0x3d4, 0x0E);
	offset |= ((WORD)(inb(0x3d5)) << 8);
	outb(0x3d4, 0x0F);
	offset |= ((WORD)(inb(0x3d5)));
	return offset;
}
