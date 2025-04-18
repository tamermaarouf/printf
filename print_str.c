#include "main.h"

/**
 * print_str - print a string.
 * @arg: argumen t.
 * Return: the length of the string.
 */

int print_str(t_data *data, va_list arg)
{
	char *str;

	str = va_arg(arg, char *);
	while (*str != '\0')
		data->buff[data->buffer_index++] = *str++;
	return (0);
}
