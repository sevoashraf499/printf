#include "main.h"
/**
 * print_octal - Prints an unsigned number in octal notation
 * @args: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_octal(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size)
{
	int index = BUFF_SIZE - 2;
	unsigned long int number = va_arg(args, unsigned int long);
	unsigned long int initialNumber = number;

	UNUSED(width);
	number = convert_size_unsigned(number, size);
	if (number == 0)
		outputBuffer[index--] = '0';
	outputBuffer[BUFF_SIZE - 1] = '\0';
	/* Convert the number to octal representation*/
	while (number > 0)
	{
		outputBuffer[index--] = (number % 8) + '0';
		number /= 8;
	}
	if (flags & FLAG_HASH && initialNumber != 0)
		outputBuffer[index--] = '0';
	index++;
	return (write_unsigned(0, index, outputBuffer,
				flags, width, precision, size));
}
