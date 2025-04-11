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
	int count;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '\0')
			return (count);
		if (*format == '%')
		{
			if ((*(++format) != '%'))
			{
				f = get_op_func(format);
				if (f != NULL)
					count += f(ap);
			}
			else
			{
				++format;
				count++;
			}

		}
		else
			count += write(1, format, 1);
		format++;
	}	
	va_end(ap);
	return (count);
}
