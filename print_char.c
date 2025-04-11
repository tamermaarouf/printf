#include "main.h"

/**
 * print_char - writes the character c to stdout
 * @arg: The character to print
 * Return: 1
 */
int print_char(va_list arg)
{
	int c = va_arg(arg, int);

	_putchar(c);
	return (1);
}
