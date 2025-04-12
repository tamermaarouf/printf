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
	int digit = number % 10;
	if (number != 0)
		recursive(number / 10);
	return (_putchar((digit) + 48));
}
