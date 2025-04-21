#include "main.h"

/**
 * print_str - print a string.
 * @data: pointer to struct
 * @arg: argumen t.
 * Return: the length of the string.
 * [-][width][.percision]
 */

int print_str(t_data *data, va_list arg)
{
	char *str;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(null)";


	while (*str != '\0')
		putchar_buf_n((char)*str++, 1, data);
	/*data->buff[data->buffer_index++] = *str++;*/
	return (0);
}
