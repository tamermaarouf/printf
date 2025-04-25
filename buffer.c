#include "main.h"

/**
 * flush_buf - write char to stout
 * @data: pointer to struct
 * Return: void
 */
void flush_buf(t_data *data)
{
	data->chars_written += write(STDOUT_FILENO,
				data->buff,
				data->buffer_index);
	_memset(data->buff, -1, BUFF_SIZE);
	data->buffer_index = 0;
}

/**
 * write_buf - write char to array of string
 * @data: pointer to struct
 * @c: char to write to buffer
 * Return: void
 */
void write_buf(t_data *data, char c)
{
	if ((data->buffer_index >= BUFF_SIZE) || c == BUF_FLUSH)
		flush_buf(data);
	data->buff[data->buffer_index++] = c;
}

/**
 * putchar_buf_n - function to write a char n times useful for padding
 * @c: char to write
 * @percision: space counter padding
 * @data: pointer to struct
 * Return: void
 */

void putchar_buf_n(char c, int percision, t_data *data)
{
	if (percision <= 0)
		return;
	while (percision--)
		write_buf(data, c);
}

/**
 * putstr_buf_n - function to write a str with a refined control
 * @str: pointer to string
 * @percision: padding
 * @data: pointer to struct
 *
 * over percision in buf
 */
void putstr_buf_n(char *str, int percision, t_data *data)
{
	if (percision <= 0)
		return;
	while (percision-- && *str)
		write_buf(data, *str++);
}
