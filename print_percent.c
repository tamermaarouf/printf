#include "main.h"

/**
 * print_percent - prints string
 * @p: argument pointer
 *
 * Return: number chars printed
 */
int print_percent(va_list p)
{
	printf("per===%i\n", va_arg(p, int));
	(void)p;
	_putchar(37);
	return (1);
}
