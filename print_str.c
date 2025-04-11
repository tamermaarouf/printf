#include "main.h"

/**
 * print_str - print a string.
 * @arg: argumen t.
 * Return: the length of the string.
 */

int print_str(va_list arg)
{
	int count;
	char *str;

	str = va_arg(arg, char *);
	count = 0;
	while (*str != '\0')
		count += write(1, str++, 1);
	return (count);
}
