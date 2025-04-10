#include "main.h"


int get_op_func(char spec, va_list arg)
{
	op_t ops[] = {
		{"c", print_char},
		{"s", print_str},
		{NULL, NULL}
	};
	int i = 0, count = 0;

	while (ops[i].op)
	{
		if ((*(ops + i)->op) == spec)
		{
			count += (ops + i)->f(arg);
		}
		i++;
	}
	return count;
}
