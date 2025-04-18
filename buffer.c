#include "main.h"


void flush_buf(t_data *data)
{
	data->chars_written += write(STDOUT_FILENO,
				data->buff,
				data->buffer_index);
	_memset(data->buff, 0, BUFF_SIZE);
	data->buffer_index = 0;
}

void write_buf(t_data *data, char c)
{
	if (data->buffer_index == BUFF_SIZE)
		flush_buf(data);
	data->buff[data->buffer_index++] = c;
}
