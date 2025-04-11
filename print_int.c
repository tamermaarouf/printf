#include "main.h"

int print_int(va_list arg)
{
	int count, n;
	count = 0;
	n = va_arg(arg, int);
	if (n < 10)
		_putchar(n);
	return (count);
}
