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
	if (digit / 10 > 0)
		return (recursive(digit / 10) % 10);
	return (1);
}
