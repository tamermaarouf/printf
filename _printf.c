#include "main.h"

int _printf(const char *format, ...)
{
	va_list ap;
	int (*f)(va_list);
	int 	count, i;

	if (format == NULL)
		return (-1);
	va_start(ap, format);
	count = 0;
	i = 0;
	while (format[i])
	{
		while (format[i] != '%' && format[i])
		{
			_putchar(format[i]);
			count++;
			i++;
		}
		if (format[i] == '\0')
			return (count);
		if (format[i] == '%')
			f = get_op_func(&format[i + 1]);
		if (f != NULL)
		{
			count += f(ap);
			i += 2;
			continue;
		}
		if (!format[i + 1])
			return (-1);
		_putchar(format[i]);
		count++;
		i++;
	}
	va_end(ap);
	return (count);
}
