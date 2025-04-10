#include "main.h"

int print_str(va_list arg)
{
	int count, i;
       	char *str;

	count = 0;
	str = va_arg(arg, char *);
	if (str == NULL)
	{
		str = "(null)";
		count = _strlen(str);
		for (i = 0; i < count; i++)
			_putchar(str[i]);
		return (count);
	}
	else
	{
		count = _strlen(str);
		for (i = 0; i < count; i++)
			_putchar(str[i]);
		return (count);
	}
	/*
	while (*str)
	{
		print_char(arg);
		++count;
		++str;
	}
	return count;
	*/
}
