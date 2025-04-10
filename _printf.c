#include "main.h"

int _printf(const char *format, ...)
{
	va_list ap;
	int 	count;

	va_start(ap, format);
	count = 0;
	while (*format != '\0')
	{
		if (*format == '%')
			count += get_op_func(*(++format), ap);
		else
			count += write(1, format, 1);
		++format;
	}
	va_end(ap);
	return (count);
}
