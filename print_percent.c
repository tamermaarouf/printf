#include "main.h"

/**
 * print_percent - prints string
 * @data: Pointer to struct
 * @p: argument pointer
 *
 * Return: number chars printed
 */
int print_percent(t_data *data, va_list p)
{
	(void)p;
	data->buff[data->buffer_index++] = '%';
	return (1);
}
