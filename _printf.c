#include "main.h"

/**
 * init_data - function to reset param
 * @data: pointer to struct bool
 * @fmt: pointer copy to argument
 * Return: Alawys return success
 */

int init_data(t_data *data, const char *fmt)
{
	data->frm.width_value = 0;
	data->frm.hash = 0;
	data->frm.left_justified = 0;
	data->frm.plus = 0;
	data->frm.space = 0;
	data->frm.zero_pad = 0;
	data->frm.percision_value = INT_MAX;
	data->chars_written = 0;
	data->s = fmt;
	data->buff = malloc(BUFF_SIZE * sizeof(char));
	if (data->buff == NULL)
		return (-1);
	data->buf_num = malloc(BUFF_SIZE * sizeof(char));
	if (data->buf_num == NULL)
		return (-1);
	data->buffer_index = 0;
	data->buffer_digit = 0;
	_memset(data->buff, -1, BUFF_SIZE * sizeof(char));
	return (0);
}

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
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	while (*data.s)
	{
		if (*data.s == '\0')
			return (data.chars_written);
		if (*data.s == '%' && *(++data.s))
		{
			if (parse_format(&data))
				return (-1);
			/*render_format(&data);*/
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
