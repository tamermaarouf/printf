#include "main.h"

/**
 * set_str_padding_spaces - get padding spaces
 * @data: pointer to struct
 * @s: char
 * Return: void
 */

void set_str_padding_spaces(t_data *data, char *s)
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
