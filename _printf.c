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

	if (init_data(&data, format))
		return (-1);
	va_start(data.ap, format);
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
