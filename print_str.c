#include "main.h"

int print_str(va_list arg)
{
	int count;
       	char *str;

	str = va_arg(arg, char *);
	count = 0;
	while (*str)
	{
		print_char(arg);
		++count;
		++str;
	}
	return count;
}
