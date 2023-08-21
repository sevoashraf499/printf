#include "main.h"
/**
 * print_string - Prints a string
 * @args: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_string(va_list args, char outputBuffer[], int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(args, char *);

	UNUSED(outputBuffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	/* Handle NULL string*/
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}
	/* Calculate string length*/
	while (str[length] != '\0')
		length++;
	/* Apply precision if specified*/
	if (precision >= 0 && precision < length)
		length = precision;
	/* Handle width*/
	if (width > length)
	{
		if (flags & FLAG_MINUS)
		{
			write(1, str, length);
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (i = width - length; i > 0; i--)
				write(1, " ", 1);
			write(1, str, length);
			return (width);
		}
	}
	return (write(1, str, length));
}
