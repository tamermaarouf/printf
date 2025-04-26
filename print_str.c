#include "main.h"

/**
 * print_string - print a string.
 * @data: pointer to struct
 * @arg: argumen t.
 * Return: the length of the string.
 * [-][width][.percision]
 */

int print_string(t_data *data, va_list arg)
{
	char *str;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = NULL_STRING;

	set_str_padding_spaces(data, str);
	if (data->frm.left_justified > 0)
	{
		if (data->frm.percision_value >= 0)
			putstr_buf_n(str, data->frm.percision_value, data);
		else
			putstr_buf_n(str, _strlen(str), data);
		putchar_buf_n(' ', data->frm.padding_space, data);
	}
	else
	{
		putchar_buf_n(' ', data->frm.padding_space, data);
		if (data->frm.percision_value >= 0)
			putstr_buf_n(str, data->frm.percision_value, data);
		else
			putstr_buf_n(str, _strlen(str), data);
	}
	/*data->buff[data->buffer_index++] = *str++;*/
	return (1);
}
