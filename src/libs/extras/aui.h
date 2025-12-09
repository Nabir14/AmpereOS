#ifndef AUI_H
#define AUI_H

#include "types.h"

void aui_draw_border(BYTE color);

WORD aui_get_center_col(WORD string_len, WORD col_size);

WORD aui_get_center_row(WORD row_size);

#endif
