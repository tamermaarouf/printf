#include "main.h"

/**
 * render_format - get the function pointer
 * @data: struct
 * Return: function pointer or NULL
 */

int (*render_format(t_data * data))(t_data *, va_list)
{
	op_t ops[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{"i", print_int},
		{"d", print_dec},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op)
	{
		if ((*(ops + i)->op) == data->frm.specifier)
			return ((ops + i)->f);
		++i;
	}
	return (NULL);
}
