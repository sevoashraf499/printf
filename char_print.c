#include "main.h"
/**
 * print_character - Prints a character
 * @args: List of arguments
 * @outBuf: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_character(va_list args,
		char outBuf[], int flags, int width, int precision, int size)
{
	char cha = va_arg(args, int);

	return (handle_write_char(cha, outBuf, flags, width, precision, size));
}
