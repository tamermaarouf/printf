#include "main.h"
/**
 *  _printf - is a function that selects the correct function to print.
 *  @format: identifier to look for.
 *  Return: the length of the string.
 */

int init_data(t_data *data, const char *fmt)
{
	data->chars_written = 0;
	data->s = fmt;
	data->buff = malloc(BUFF_SIZE * sizeof(char));
	if (data->buff == NULL)
		return (-1);
	data->buffer_index = 0;
	return (0);
}

int _printf(const char *format, ...)
{
	t_data data;

	va_start(data.ap, format);
	if (init_data(&data, format))
		return (-1);
	/*
	va_list ap;
	int (*f)(va_list);
	int count, index, buff_index;
	char *ptr;
	char r[BUFF_SIZE];

	ptr = (char *)format;
	count = 0, index = 0, buff_index = 0;*/
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	while (*data.s)
	{
		if (*data.s == '%' && *(++data.s))
		{
			if (parse_format(&data))
				return (-1);
			/*render_format(&data);*/
		}
		else
		{
			write_buf(&data, *data.s);
		}
		++data.s;
	}
	flush_buf(&data);
	va_end(data.ap);
	free(data.buff);
	return (data.chars_written);
	/**
	while (ptr[index] != '\0' && ptr)
	{
		while (ptr[index] != '%' && ptr[index])
		{
			r[buff_index] = ptr[index];
			_putchar(ptr[index]);
			count += write(1, &ptr[index], 1);
			index++, buff_index++;
		}
		if (ptr[index] == '\0')
			return (count);
		index++;
		if (*(ptr + index) == '%')
			count += _putchar('%');
		else
		{
			f = get_op_func(&ptr[index]);
			if (f != NULL)
				count += f(ap);
		}
		index++;
		r[buff_index + 1] = '\0';
	}
	print_buffer(r, &buff_index);
	va_end(ap);
	return (count);
	*/
}
