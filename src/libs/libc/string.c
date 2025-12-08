#include "string.h"

WORD pstring_len(const pSTRING string)
{
	pSTRING pstr = string;
	
	while(*pstr != '\0')
	{
		pstr++;
	}

	return (pstr - string);
}
