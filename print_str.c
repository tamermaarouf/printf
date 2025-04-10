#include "main.h"

int print_str(va_list arg)
{
	int count;
       	char *str;

	count = 0;
	str = va_arg(arg, char *);
	while (*str)
	{
		print_char(arg);
		++count;
		++str;
	}
	return count;
}
