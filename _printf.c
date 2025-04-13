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
	char buffer[BUFF_SIZE];

	if (format == NULL || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(ap, format);
	count = 0;
	index = 0;
	while (*format)
	{
		if (*format == '\0')
			return (count);
		if (*format == '%')
		{
			format++;
			if (*format == '%')
			{
				buffer[index++] = '%';
				if (index <= BUFF_SIZE)
				{
					print_buffer(buffer, &index);
					count += index;
				}
			}
			else
				f = get_op_func(&format[index]);
			if (f != NULL)
				count += f(ap);
		}
		else
		{
			buffer[index++] = *format;
			if (index <= BUFF_SIZE)
			{
				print_buffer(buffer, &index);
				count += index;
			}
		}
		format++;
	}
	count += index;
	va_end(ap);
	return (count);
}
