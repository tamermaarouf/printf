#include "main.h"

/**
 *  _printf - is a function that selects the correct function to print.
 *  @format: identifier to look for.
 *  Return: the length of the string.
 */

int _printf(const char *format, ...)
{
	t_data data;

	va_start(data.ap, format);
	if (init_data(&data, format))
		return (-1);
	while (*data.s)
	{
		if (*data.s == '\0')
			return (data.chars_written);
		if (*data.s == '%' && *(++data.s))
			parse_format(&data);
		else
			write_buf(&data, *data.s);
		++data.s;
	}
	flush_buf(&data);
	va_end(data.ap);
	free(data.buff);
	return (data.chars_written);
}
