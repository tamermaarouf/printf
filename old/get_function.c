#include "main.h"


/**
 * get_op_func - function that finds formats for _printf
 * @spec: pointer to char
 * Return: NULL or function associated
 */

int (*get_op_func(const char *spec))(va_list)
{
	op_t ops[] = {
		{"c", print_char},
		{"s", print_str},
		{"%", print_percent},
		{"i", print_int},
		{"d", print_dec},
		{"b", print_bin},
		{NULL, NULL}
	};
	int i = 0;

	while (ops[i].op)
	{
		if ((*(ops + i)->op) == *spec)
			return ((ops + i)->f);
		i++;
	}
	return (NULL);
}
