#include "main.h"

int print_int(va_list arg)
{

	printf("print_int: %d", va_arg(arg, int));
	return (2);
}
