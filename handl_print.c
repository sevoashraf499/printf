#include "main.h"
/**
 * handle_print - Prints an argument based on its type
 * @fmt: Formatted string in which to print the arguments.
 * @ind: Pointer to the index of the current character in the format string.
 * @list: List of arguments to be printed.
 * @buffer: Buffer array to handle print.
 * @flags: Active flags.
 * @width: Width specification.
 * @precision: Precision specification.
 * @size: Size specifier.
 * Return: Number of characters printed or -1 for error.
 */
int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
		int flags, int width, int precision, int size)
{
	int i, unknown_len = 0, printed_chars = -1;

	/* Array of format types and their respective functions*/
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	/*Loop through the fmt_types array to find a matching format type*/
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
	{
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));
	}
	/*If no matching format type is found*/
	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		/* Error: Reached end of format string without matching format t*/
		unknown_len += write(1, "%", 1); /* Print '%'*/
		if (fmt[*ind - 1] == ' ')
			unknown_len += write(1, " ", 1);
		/* Print space if previous character was a space*/
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
		}
		if (fmt[*ind] == ' ')
			--(*ind);
		return (1); /*Return 1 to indicate width specification*/
	}
	unknown_len += write(1, &fmt[*ind], 1); /* Print the unknown character*/
	return (unknown_len);
}
return (printed_chars);
}
