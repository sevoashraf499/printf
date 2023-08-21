#include "main.h"
/**
 * print_pointer - Prints the value of a pointer variable
 * @args: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: Width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_pointer(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size)
{
	char extraChar = 0, paddingChar = ' ';
	int index = BUFF_SIZE - 2, length = 2, paddingStart = 1;
	/* length=2, for '0x' */
	unsigned long numAddresses;
	char mapTo[] = "0123456789abcdef";
	void *addresses = va_arg(args, void *);

	UNUSED(width);
	UNUSED(size);

	if (addresses == NULL)
		return (write(1, "(nil)", 5));
	outputBuffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);
	numAddresses = (unsigned long)addresses;
	while (numAddresses > 0)
	{
		outputBuffer[index--] = mapTo[numAddresses % 16];
		numAddresses /= 16;
		length++;
	}
	if ((flags & FLAG_ZERO) && !(flags & FLAG_MINUS))
		paddingChar = '0';
	if (flags & FLAG_PLUS)
		extraChar = '+', length++;
	else if (flags & FLAG_SPACE)
		extraChar = ' ', length++;
	index++;
	return (write_pointer(outputBuffer, index, length,
				width, flags, paddingChar, extraChar, paddingStart));
}
