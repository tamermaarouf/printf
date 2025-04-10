#include "main.h"

	int print_char(va_list arg)
	{
	int c = va_arg(arg, int);
	_putchar(c);
	return(1);
}
