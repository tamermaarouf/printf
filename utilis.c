#include "main.h"


bool in(const char *s, char c)
{
	if (s == NULL)
		return false;
	while (*s)
	{
		if (*s == c)
			return true;
		++s;
	}
	return false;
}

/**
 *
void _memset(void *ptr, int value, size_t n)
{
	byte *ptr_byte;

	ptr_byte = (byte *)ptr;
	while (n)
	{
		*ptr_byte = value;
		--n;
	}
}
*/
