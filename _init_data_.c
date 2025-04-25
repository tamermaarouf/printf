#include "main.h"

/**
 * init_data - function to reset param
 * @data: pointer to struct bool
 * @fmt: pointer copy to argument
 * Return: Alawys return success
 */

int init_data(t_data *data, const char *fmt)
{
	data->s = fmt;
	data->chars_written = 0;
	data->buff = malloc(BUFF_SIZE * sizeof(char));
	if (data->buff == NULL)
		return (-1);
	data->buf_num = malloc(BUFF_SIZE * sizeof(char));
	if (data->buf_num == NULL)
		return (-1);
	data->buffer_index = 0;
	data->buffer_digit = 0;
	return (0);
}
