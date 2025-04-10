#include "main.h"



/**
 * print_char - writes the character c to stdout
 * @arg: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int print_char(va_list arg)
{
	int c = va_arg(arg, int);

	_putchar(c);
	return (1);
}
