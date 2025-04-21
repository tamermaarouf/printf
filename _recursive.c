#include "main.h"

/**
 * recursive - function return one char to caller
 * @number: number to rec
 * Return: return one char
 */

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
