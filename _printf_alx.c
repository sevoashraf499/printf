#include "main.h"
void print_buffer(char buffer[], int *buff_ind);
/**
 * _printf - prints all specifer and % handeles
 * @format: the character string argument
 * Return: thee number of printed characters to stdout
 */
int _printf(const char *format, ...)
{
	int i, printed = 0, printedChars = 0;
	int activeFlags, fieldWidth, precision, specifierSize, bufferIndex = 0;
	va_list args;
	char outputBuffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(args, format);

	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			outputBuffer[bufferIndex++] = format[i];
			if (bufferIndex == BUFF_SIZE)
				write_buffer(outputBuffer, &bufferIndex);
			printedChars++;
		}
		else
		{
			write_buffer(outputBuffer, &bufferIndex);
			activeFlags = get_flags(format, &i); /*active flags frm format stri*/
			fieldWidth = get_width(format, &i, args); /*field widthformat string*/
			precision = get_precision(format, &i, args); /*get precicion*/
			specifierSize = get_size(format, &i); /*get size specifier*/
			++i;
			printed = handle_print(format, &i, args, outputBuffer,
				activeFlags, fieldWidth, precision, specifierSize);
			if (printed == -1)
				return (-1);
			printedChars += printed;
		}
	}

	write_buffer(outputBuffer, &bufferIndex);

	va_end(args);

	return (printedChars);
}

/**
 * write_buffer - Prints the contents of the buffer if it exists
 * @outputBuffer: Array of characters.
 * @bufferIndex: Index at which to add the next charact length.
 */
void write_buffer(char outputBuffer[], int *bufferIndex)
{
	if (*bufferIndex > 0)
		write(1, &outputBuffer[0], *bufferIndex); /* Write the buffer content*/

	*bufferIndex = 0;
}
