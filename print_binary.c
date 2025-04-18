#include "main.h"

int print_bin(va_list ap)
{
	unsigned long int n;
	unsigned int count;

	n = va_arg(ap, unsigned long int);
	count = 0;
	count += print_binary(n);
	return (count);
}

/**
 * print_binary - prints the binary representation of a number.
 * @n :representation of a number.
 * Return: 0 Always Success
 */

int print_binary(unsigned long int n)
{
	if (n > 1)
		print_binary(n >> 1);
	return (_putchar((n & 1) + '0'));
}
