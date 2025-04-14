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

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format [2])
		return (-1);
	va_start(ap, format);
	count = 0;
	index = 0;
	while (format[index] != '\0' && format)
	{
		while (format[index] != '%' && format[index])
		{
			_putchar(format[index]);
			count++;
			index++;
		}
		if (format[index] == '\0')
			return (count);
		index++;
		if (*(format + index) == '%')
			count += _putchar('%');
		else
		{
			f = get_op_func(&format[index]);
			if (f != NULL)
				count += f(ap);
		}
		index++;
	}
	va_end(ap);
	return (count);
}
