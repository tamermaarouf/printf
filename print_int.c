#include "main.h"

/**
 * print_int - function to print integer spec [i]
 * @data: pointer to struct
 * @arg: handle argument
 * Return: always return success
 */
int print_int(t_data *data, va_list arg)
{
	int N, i;

	N = va_arg(arg, int);
	data->buffer_digit = 0;
	if (N < 0)
	{
		data->buf_num[data->buffer_digit++] = '-';
		N = -N;
	}
	if (N > 9)
	{
		while (N)
		{
			/**
			 * Separate last digit from
			 * the number and add ASCII
			 * value of character '0' is 48
			 */
			data->buf_num[data->buffer_digit++] = ((N % 10) + 48);
			/**
			 * Truncate the last
			 * digit from the number
			 */
			N /= 10;
		}
	}
	for (i = data->buffer_digit; i >= 0; i--)
		data->buff[data->buffer_index++] = data->buf_num[i];

	return (data->buffer_index);
}
