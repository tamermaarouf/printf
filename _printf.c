#include "main.h"

/**
 *  _printf - is a function that selects the correct function to print.
 *  @format: identifier to look for.
 *  Return: the length of the string.
 */

int _printf(const char *format, ...)
{
	va_list ap;
	int (*f)(va_list);
	int count, index;

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);
	count = 0;
	index = 0;
	while (format && format[index])
	{
		if (format[index] == '\0')
			return (count);
		if (format[index] == '%')
		{
			if (format[++index] != '%')
			{
				f = get_op_func(&format[index]);
				if (f != NULL)
				{
					count += f(ap);
					index += 1;
					continue;
				}
			}
			else
				count += write(1, &format[index], 1);
		}
		else
			count += write(1, &format[index], 1);
		index++;
	}
	va_end(ap);
	return (count);
}
