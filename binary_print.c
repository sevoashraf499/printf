#include "main.h"
/**
 * print_binary - Prints an unsigned number in binary format
 * @args: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_binary(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size)
{
	unsigned int num, divisor, i, sum;
	unsigned int binaryDigits[32];
	int count;

	UNUSED(outputBuffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	num = va_arg(args, unsigned int);
	divisor = 2147483648; /* (2 ^ 31) */
	binaryDigits[0] = num / divisor;
	/* Convert the number to binary representation*/
	for (i = 1; i < 32; i++)
	{
		divisor /= 2;
		binaryDigits[i] = (num / divisor) % 2;
	}
	/*Print the binary digits*/
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += binaryDigits[i];
		if (sum || i == 31)
		{
			char digitChar = '0' + binaryDigits[i];

			write(1, &digitChar, 1);
			count++;
		}
	}
	return (count);
}
