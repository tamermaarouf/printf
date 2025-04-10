#include "main.h"

int print_char(va_list arg)
{
	int c = va_arg(arg, int);
	return (write(1, &c, 1));
}
