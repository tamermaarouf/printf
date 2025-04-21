#include "main.h"

/**
 * set_str_padding_spaces - get padding spaces
 * @data: pointer to struct
 * @s: char
 * Return: void
 */

static void set_str_padding_spaces(t_data *data, char *s)
{
	int len;

	len = _strlen(s);
	/*check if width*/
	if (data->frm.width_value > 0)
	{
		/*check if percision*/
		if (data->frm.percision_value > 0)
		{
			if (data->frm.percision_value > len)
				data->frm.padding_space = data->frm.width_value - len;
			else if (data->frm.percision_value < len)
				data->frm.padding_space = data->frm.width_value -
					data->frm.percision_value;
		}
		else
			data->frm.padding_space = data->frm.width_value - len;
	}
}
/**
 * print_str - print a string.
 * @data: pointer to struct
 * @arg: argumen t.
 * Return: the length of the string.
 * [-][width][.percision]
 */

int print_str(t_data *data, va_list arg)
{
	char *str;

	str = va_arg(arg, char *);
	if (str == NULL)
		str = "(null)";

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
	return (0);
}
