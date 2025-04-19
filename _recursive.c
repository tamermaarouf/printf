#include "main.h"

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
	return ((digit % 10) + 48);
}
