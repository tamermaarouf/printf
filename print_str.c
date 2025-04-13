#include "main.h"

/**
 * print_str - print a string.
 * @arg: argumen t.
 * Return: the length of the string.
 */

int print_str(va_list arg)
{
	int count, i;
	char *str;

	str = va_arg(arg, char *);
	if (str == NULL)
	{
		i = 0;
		str = "(null)";
		count = _strlen(str);
		while (i < count)
		{
			write(1, &str[i], 1);
			++i;
		}
		return (count);
	}
	else
	{
		count = 0;
		while (*str != '\0')
			count += write(1, str++, 1);
		return (count);
	}
}
