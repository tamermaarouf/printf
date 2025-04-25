#include "main.h"

/**
 *  _printf - is a function that selects the correct function to print.
 *  @format: identifier to look for.
 *  Return: the length of the string.
 */

int _printf(const char *format, ...)
{
	t_data data;
	int (*f)(t_data *data, va_list);

	va_start(data.ap, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	if (init_data(&data, format))
		return (-1);
	while (*data.s)
	{
		if (*data.s == '\0')
			return (data.chars_written);
		if (*data.s == '%' && *(++data.s))
		{
			if (parse_format(&data))
				return (-1);
			f = render_format(&data);
			if (f != NULL)
				f(&data, data.ap);

		}
		else
			write_buf(&data, *data.s);
		++data.s;
	}
	flush_buf(&data);
	va_end(data.ap);
	free(data.buff);
	return (data.chars_written);
}
