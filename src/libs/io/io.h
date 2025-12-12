#ifndef IO_H
#define IO_H

#include "../extras/types.h"

void outb(WORD port, BYTE value);
BYTE inb(WORD port);

#endif
