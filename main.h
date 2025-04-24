#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdbool.h>
#include <limits.h>


#define BUFF_SIZE 1024
#define FLAGS "+- 0#"
#define NUMBER "0123456789"
#define SPECIFIER "diuoxXfFeEgGaAcspn%"
#define INT_MAX __INT_MAX__
typedef unsigned char byte;
struct s_data;  
/*typedef enum
{
	BASE_2 = 2,
	BASE_8 = 8,
	BASE_10 = 10,
	BASE_16 = 16,
} e_base;

typedef enum E_base
{
	OK = 0,
	MALLOC_ERROR = -1337,
	PARSE_ERROR = -42,
} e_error;*/

typedef struct s_format
{
	/*flag*/
	byte left_justified;
	byte plus;
	byte space;
	byte hash;
	byte zero_pad;
	/* "csdixXpu...."*/
	char specifier;
	/* width + percision */
	int width_value;
	int percision_value;
	int padding_space;

	/*e_base base;*/
}t_format;


typedef struct s_data
{
	/* pointer copy to format*/
	const char *s;
	/* va_list ->va_arg(ap, int) */
	va_list ap;

	/* chars written */
	int chars_written;

	/* buffer  in the HEAP*/ 
	char *buff;
	int buffer_index;
	/* buffer for number */
	char *buf_num;
	int buffer_digit;

	/* All the bools [+=' '0#][width][.percision] */
	t_format frm;
}t_data;
/**
 * struct op - Struct op
 *
 * @op: The operator
 * @f: The function associated
 */

typedef struct op
{
	char *op;
	int (*f)(t_data *, va_list);
} op_t;


int _putchar(char c);
int _strlen(char *s);
int print_char(t_data *, va_list);
int print_str(t_data *, va_list);
int print_percent(t_data *, va_list);
int recursive(int number);
int print_dec(t_data *, va_list);
int print_int(t_data *, va_list);/*
int print_bin(t_data *, va_list);
int print_binary(unsigned long int); 
int (*get_op_func(const char *))(va_list);*/
void print_buffer(char buffer[], int *buff_ind);
int _printf(const char *format, ...);
bool in(const char *s, char c);
int parse_format(t_data *);
int my_atoi(t_data *);
void parse_flags(t_data *);
void get_value(t_data *, int *);
void write_buf(t_data *, char);
void flush_buf(t_data *);
void putchar_buf_n(char c, int percision, t_data *data);
void putstr_buf_n(char *str, int percision, t_data *data);
void _memset(void *, byte , size_t);
int (*render_format(t_data *))(t_data *, va_list);
int init_data(t_data *data, const char *fmt);
#endif /*MAIN_H*/

