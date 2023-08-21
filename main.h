#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define FLAG_MINUS (1 << 0)
#define FLAG_PLUS (1 << 1)
#define FLAG_ZERO (1 << 2)
#define FLAG_HASH (1 << 3)
#define FLAG_SPACE (1 << 4)

/* SIZES */
#define SIZE_LONG (1 << 0)
#define SIZE_SHORT (1 << 1)

/**
 * struct Format - Struct Format
 * @specifier: The format specifier.
 * @handler: The function associated.
 */
typedef struct Format
{
	char specifier;
	int (*handler)(va_list, char[], int, int, int, int);
} Format_t;
int _printf(const char *format, ...);
int handle_print(const char *specifier, int *i, va_list args,
		char outputBuffer[], int flags, int width, int precision, int size);

/****************** FUNCTIONS ******************/

/* Functions to print chars and strings */
int print_character(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size);
int print_string(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size);
int print_percent(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size);

/* Functions to print numbers */
int print_integer(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size);
int print_binary(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size);
int print_unsigned(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size);
int print_octal(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal_upper(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size);
int print_hexadecimal(va_list args, char mapTo[], char outputBuffer[],
		int flags, char flagChar, int width, int precision, int size);
/* Function to print non-printable characters */
int print_non_printable(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size);
/* Function to print memory address */
int print_pointer(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size);
/* Functions to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list args);
int get_precision(const char *format, int *i, va_list args);
int get_size(const char *format, int *i);
/* Function to print string in reverse */
int print_reverse(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size);
/* Function to print a string in rot13 */
int print_rot13_string(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size);
/* Width handler */
int handle_write_char(char c, char outputBuffer[],
		int flags, int width, int precision, int size);
int write_number(int isPositive, int index, char outputBuffer[],
		int flags, int width, int precision, int size);
int write_num(int index, char bff[], int flags, int width,
		int precision, int length, char padding, char extraChar);
int write_pointer(char outputBuffer[], int index, int length,
		int width, int flags, char padding, char extraChar, int paddingStart);
int write_unsigned(int isNegative, int index, char outputBuffer[],
		int flags, int width, int precision, int size);
/****************** UTILS ******************/
int is_printable(char character);
int append_hexa_code(char character, char[], int);
int is_digit(char character);

long int convert_size_number(long int number, int size);
long int convert_size_unsigned(unsigned long int number, int size);

#endif
