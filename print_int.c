#include "main.h"

int print_int(t_data *data, va_list arg)
{
	int n;

	n = va_arg(arg, int);
	data->buff[data->buffer_index++] = recursive(n);
	return (0);
}
