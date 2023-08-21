#include "main.h"
/**
 * print_non_printable - Prints ASCII codes in hexadecimal for non-prin
 * @args: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_non_printable(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size)
{
	int index = 0; /*Index of the output buffer*/
	int offset = 0; /* offset for handling non-printable characters*/
	char *str = va_arg(args, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));
	/* Handle case when the input string is NULL*/
	while (str[index] != '\0')
	{
		if (is_printable(str[index]))
			outputBuffer[index + offset] = str[index];
		/* Store printable characters directly*/
		else
			offset += append_hexa_code(str[index], outputBuffer, index + offset);
		/* Append hexadecimal code for non-printable characters*/
		index++;
	}
	outputBuffer[index + offset] = '\0'; /*Null-terminate the output buffer*/
	return (write(1, outputBuffer, index + offset));
	/*Write the output buffer to the output*/
}
