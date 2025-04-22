#include "main.h"

/**
 * my_atoi - convert ascii to int i
 * @data: pointer to struct
 * Return: value int
 */

int my_atoi(t_data *data)
{
	int value;

	value = 0;
	while (in(NUMBER, *data->s))
		value = (value * 10) + (*data->s++ - 48);
	return (value);
}

/**
 * parse_flags - get flags[0-+#' '] to true
 * @data: pointer to struct
 * Retrun: coid
 */
void parse_flags(t_data *data)
{
	char flag;

	while (in(FLAGS, *data->s))
	{
		flag = *data->s;
		switch (flag)
		{
			case '0':
				data->frm.zero_pad = 1;
				break;
			case '+':
				data->frm.plus = 1;
				break;
			case ' ':
				data->frm.space = 1;
				break;
			case '#':
				data->frm.hash = 1;
				break;
			case '-':
				data->frm.left_justified = 1;
				break;
		}
		++data->s;
	}
}

/**
 * get_value - get value from va_list
 * @data: pointer to struct
 * @value: number
 * Return: void
 */

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

/**
 * parse_format - call function to reset frm
 * @data: pointer to struct
 * Return: Always return success
 */

int parse_format(t_data *data)
{
	int (*f)(t_data *data, va_list);
	/* 0 refresh the data*/
	_memset(&data->frm, -1, sizeof(t_format));
	data->frm.percision_value = -1;
	printf("current:%c\n", *data->s);

	/*1 [0-' '#+]*/
	parse_flags(data);

	/* 2 [width *] */
	get_value(data, &data->frm.width_value);
	/*3 [.percision_value *]*/
	if (*data->s == '.' && *(++data->s))
		get_value(data, &data->frm.percision_value);
	if (!in(SPECIFIER, *data->s))
		return (-1);
	data->frm.specifier = *data->s;
	f = render_format(data);
	if (f != NULL)
		f(data, data->ap);
	/**
	 * if(in("diu", data->frm.specifier))
	 * data->frm.base = BASE_10;
	 * else if (in("xXp", data->frm.specifier))
	 * {
	 * data->frm.base = BASE_16;
	 * }
	 */
	return (0);
}
