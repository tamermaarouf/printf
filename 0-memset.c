#include "main.h"

/**
 * _memset -  fills memory with a constant byte.
 * @s: fills the memory area
 * @b: the constant byte
 * @n: the first n bytes
 *
 * Return:  a pointer to the memory area s
 */

void _memset(void *s, byte b, size_t n)
{
	byte *ptr_byte;

	ptr_byte = (byte *)s;
	while (n > 0)
	{
		*ptr_byte++ = b;
		--n;
	}
}
