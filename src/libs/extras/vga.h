#ifndef VGA_H
#define VGA_H

#include "types.h"

#define VGA_TEXT_ADDR 0xb8000

#define MAX_COL 80
#define MAX_ROW 25

#define WHITE 0x0F
#define RED 0x0C
#define GREEN 0x0C
#define BLUE 0x01
#define LIGHT_BLUE 0x09
#define DARK_GRAY 0x08
#define LIGHT_GRAY 0x07

WORD get_offset(WORD col, WORD row);
BYTE get_col(WORD offset);
BYTE get_row(WORD offset);

#endif
