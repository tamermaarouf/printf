#include "main.h"


void flush_buf(t_data *data)
{
	data->chars_written += write(STDOUT_FILENO,
				data->buff,
				data->buffer_index);
	_memset(data->buff, -1, BUFF_SIZE);
	data->buffer_index = 0;
}

void write_buf(t_data *data, char c)
{
	if (data->buffer_index == BUFF_SIZE)
		flush_buf(data);
	data->buff[data->buffer_index++] = c;
}

/**
 * function to write a char n times
 * useful for padding with '0' or ' '
 */

void putchar_buf_n(char c, int percision, t_data *data)
{
	if (percision <= 0)
		return ;
	while (percision--)
		write_buf(data, c);
}

