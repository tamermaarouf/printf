#include "main.h"

/**
 * print_percent - prints string
 * @p: argument pointer
 *
 * Return: number chars printed
 */
int print_percent(t_data *data, va_list p)
{
	int c = va_arg(p, int);

	data->buff[data->buffer_index++] = c;
	return (0);
}
