#include "main.h"

/**
 * print_char - writes the character c to stdout
 * @arg: The character to print
 * Return: 1
 */
int print_char(t_data *data, va_list arg)
{
	int c = va_arg(arg, int);
	int width;
	width = data->frm.width_value;
	if (width > 1)
	{
		if(data->frm.left_justified)
		{
			putchar_buf_n((char)c, 1, data);
			putchar_buf_n(' ', (width - 1), data);
		}
		else
		{
			putchar_buf_n(' ', (width - 1), data);
			putchar_buf_n((char)c, 1, data);
		}
	}
	else
		putchar_buf_n((char)c, 1, data);
	/*data->buff[data->buffer_index++] = c;*/
	return (0);
}
