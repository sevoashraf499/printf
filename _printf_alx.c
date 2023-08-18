#include "main.h"
/**
 * _printf - prints normal characters, %c specifer,%s specifer and % handeles
 * @format: the character string argument
 * Return: thee number of printed characters to stdout
 */
int _printf(const char *format, ...)
{
	unsigned int i = 0;

	va_list input_arg;

	if (!*format)
		return (0);
	va_start(input_arg, format);

	for (i = 0; *format; format++, i++)
	{
		if (*format != '%')
		{
			char str = va_arg(format, char);
			write(1, str, 1);
		}
		else
		{
			format++;
			if (!*format)
				break;
			else if (*format == 'c')
			{
				char str = va_arg(format, int);
				write(1, &str, 1);
			}
			else if (*format == 's')
			{
				char *str = va_arg(format, char*);
				write(1, str, strlen(str));
				i += strlen(str);
			}
		}
	}
	va_end(input_arg);
	return (i);
}
