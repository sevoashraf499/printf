#include "main.h"
/**
 * print_int - Prints an integer
 * @args: List of arguments
 * @outputBuffer: Buffer array to handle print
 * @flags: Active flags
 * @width: Width specification
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_int(va_list args, char outputBuffer[],
		int flags, int width, int precision, int size)
{
	int index = BUFF_SIZE - 2; /*Start index of the output buffer*/
	int isNegative = 0; /*Flag to track if the number is negative*/
	long int number = va_arg(args, long int);
	unsigned long int num;

	number = convert_size_number(number, size);
	/* Convert the number based on the size specifier*/
	if (number == 0)
		outputBuffer[index--] = '0';
	/* Handle special case when the number is 0*/
	outputBuffer[BUFF_SIZE - 1] = '\0';
	/* Null-terminate the output buffer*/
	num = (unsigned long int)number;
	if (number < 0)
	{
		num = (unsigned long int)((-1) * number);
		isNegative = 1;
	}
	while (num > 0)
	{
		outputBuffer[index--] = (num % 10) + '0';
		/* Get the digit and store it in the output buffer*/
		num /= 10;
		/*Divide the number by 10 to get the next digit*/
	}
	index++;
	return (write_number(isNegative, index,
				outputBuffer, flags, width, precision, size));
	/* Write the output buffer to the output*/
}
