#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>


/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */

typedef struct op
{
	char *op;
	int (*f)(va_list);
} op_t;

int (*get_op_func(const char *))(va_list);
int _putchar(char c);
int _strlen(char *s);
int print_char(va_list);
int print_str(va_list);
int print_percent(va_list);
int print_int(va_list);
int _printf(const char *format, ...);

#endif /*MAIN_H*/

