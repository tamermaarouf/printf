#include "main.h"

int print_int(va_list arg)
{
	int count, n;
	count = 0;

	n = va_arg(arg, int);
	count += recursive(n);
	return (count);
}
