#include "main.h"

int print_int(va_list arg)
{
	int count, n;
	count = 0;

	n = va_arg(arg, int);
	if (n < 0)
	{
		_putchar('-');
		n = -n;
	}
	while ((n / 10) != 0)
	{
		_putchar((n % 10) + 48);
		n = n / 10;
		count++;
	}
	_putchar((n % 10) + 48);
	return (count);
}
