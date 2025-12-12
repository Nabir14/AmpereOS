#ifndef PRINT_H
#define PRINT_H

#include "../extras/types.h"


void print(const pSTRING string, BYTE text_color, BYTE bg_color);
void print_at_offset(const pSTRING string, BYTE text_color, BYTE bg_color, WORD col, WORD row);
void print_at_cursor(const pSTRING string, BYTE text_color, BYTE bg_color);

#endif
