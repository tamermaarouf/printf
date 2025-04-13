#include "main.h"

int print_int(va_list arg)
{
	int count, n;
	count = 0;

	n = va_arg(arg, int);
	count += recursive(n);
	return (count);
}


int recursive(int number) 
{
	unsigned int digit = number;

	if (number < 0)
	{
		_putchar('-');
		digit = -digit;
	}
	if ((digit / 10) > 0)
		recursive(digit / 10);
	return (_putchar((digit % 10) + 48));
}
