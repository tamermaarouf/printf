#include "main.h"


int (*render_format(t_data *data))(t_data *, va_list)
{
	op_t ops[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op)
	{
		if ((*(ops + i)->op) == *data->s)
			return ((ops + i)->f);
		++i;
	}
	return (NULL);
}
