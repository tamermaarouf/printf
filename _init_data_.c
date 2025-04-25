#include "main.h"

/**
 * init_data - function to reset param
 * @data: pointer to struct bool
 * @fmt: pointer copy to argument
 * Return: Alawys return success
 */

int init_data(t_data *data, const char *fmt)
{
	if (!fmt || (fmt[0] == '%' && !fmt[1]))
		return (-1);
	if (fmt[0] == '%' && fmt[1] == ' ' && !fmt[2])
		return (-1);
	data->s = fmt;
	data->frm.width_value = 0;
	data->frm.hash = 0;
	data->frm.left_justified = 0;
	data->frm.plus = 0;
	data->frm.space = 0;
	data->frm.zero_pad = 0;
	data->frm.percision_value = INT_MAX;
	data->chars_written = 0;
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
