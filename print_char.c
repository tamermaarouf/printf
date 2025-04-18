#include "main.h"

/**
 * print_char - writes the character c to stdout
 * @arg: The character to print
 * Return: 1
 */
int print_char(t_data *data, va_list arg)
{
	int c = va_arg(arg, int);
	data->buff[data->buffer_index++] = c;
	return (0);
}
