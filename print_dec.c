#include "main.h"

/**
 * print_dec - function to print integer spec [d]
 * @data: pointer to struct
 * @arg: handle argument
 * Return: always return success
 */

int print_dec(t_data *data, va_list arg)
{
	int N, i, x;

	N = va_arg(arg, int);
	x = N;
	data->buffer_digit = 0;

	if (x < 0)
	{
		data->buff[data->buffer_index++] = 0x2D;
		x = -N;
	}
	if (x > 0)
	{
		while (x)
		{
			/**
			 * Separate last digit from
			 * the number and add ASCII
			 * value of character '0' is 48
			 */
			data->buf_num[data->buffer_digit++] = ((x % 10) + 48);
			/**
			 * Truncate the last
			 * digit from the number
			 */
			x /= 10;
		}
	}
	for (i = data->buffer_digit; i >= 0; i--)
		data->buff[data->buffer_index++] = data->buf_num[i];

	return (0);

}
