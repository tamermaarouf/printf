#include "main.h"

int my_atoi(t_data *data)
{
	int value;

	value = 0;
	while (in(NUMBER, *data->s))
		value = (value * 10) + (*data->s++ - 48);
	return value;
}

void parse_flags(t_data *data)
{
	char flag;

	while (in(FLAGS, *data->s))
	{
		flag = *data->s;
		switch (flag)
		{
			case '0':
				data->frm.zero_pad = true;
				break;
			case '+':
				data->frm.plus = true;
				break;
			case ' ':
				data->frm.space = true;
				break;
			case '#':
				data->frm.hash = true;
				break;
			case '-':
				data->frm.left_justified = true;
				break;
		}
		++data->s;			
	}
}

void get_value(t_data *data, int *value)
{
	if (*data->s == '*')
	{
		*value = va_arg(data->ap, int);
		++data->s;
		return;
	}
	*value = my_atoi(data);
}
int parse_format(t_data *data)
{
	parse_flags(data);
	get_value(data, &data->frm.width_value);

	if (*data->s == '.' && *(data->s))
		get_value(data, &data->frm.percision_value);

	if(!in(SPECIFIRES, *data->s))
		return (-1);
	else
	{
		data->frm.specifier = *data->s;
		/*if(in("diu", data->frm.specifier))
			data->frm.base = BASE_10;
		else if (in("xXp", data->frm.specifier))
		{
			data->frm.base = BASE_16;

		}*/
	}
	return (0);
}
