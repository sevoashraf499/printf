#include "main.h"
/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @args: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(args, "0123456789abcdef", outputBuffer,
			flags, 'x', width, precision, size));
}
/*PRINT UNSIGNED NUMBER IN UPPER HEXADECIMAL*/
/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @args: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size)
{
	return (print_hexa(args, "0123456789ABCDEF", outputBuffer,
			flags, 'X', width, precision, size));
}

/*PRINT HEXADECIMAL NUMBER IN LOWER OR UPPER */
/**
 * print_hexa - Prints a hexadecimal number in lower or upper case
 * @args: List of arguments
 * @map_to: Array of values to map the number to
 * @outputBuffer: Buffer array to handle print
 * @flags: Active flags
 * @flagChar: Flag character
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexa(va_list args, char map_to[], char outputBuffer[],
		int flags, char flagChar, int width, int precision, int size)
{
	int index = BUFF_SIZE - 2; /*Start index of the output buffer*/
	unsigned long int number = va_arg(args, unsigned long int);
	unsigned long int initialNumber = number;

	UNUSED(width);

	number = convert_size_unsigned(number, size);
	/*Convert the number based on the size specifier*/
	if (number == 0)
		outputBuffer[index--] = '0'; /*Handle special case when the number is 0*/
	outputBuffer[BUFF_SIZE - 1] = '\0'; /*Null-terminate the output buffer*/
	/* Convert the number to hexadecimal representation*/
	while (number > 0)
	{
		outputBuffer[index--] = map_to[number % 16];
		/* Get the hexadecimal digit and store it in the output buffer*/
		number /= 16; /*Divide the number by 16 to get the next hexadecimal digit*/
	}
	if (flags & F_HASH && initialNumber != 0)
	{
		outputBuffer[index--] = flagChar;
		/*
		 * Add the flag character ('x' or 'X') if the '#'
		 * flag is set and the initial number is non-zero
		 */
		outputBuffer[index--] = '0';
		/* Add '0' prefix if the '#' flag is set and the initial number is non-zero*/
	}
	index++;
	return (write_unsigned(0, index, outputBuffer, flags,
				width, precision, size));/*Write the output buffer to the output*/
}
