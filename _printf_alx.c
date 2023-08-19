#include "main.h"
/**
 * _printf - prints normal characters, %c specifer,%s specifer and % handeles
 * @format: the character string argument
 * Return: thee number of printed characters to stdout
 */
int _printf(const char *format, ...)
{
	unsigned int i;
	char c_char;
	va_list input_arg;

	if (format == NULL)
		return (0);
	va_start(input_arg, format);

	for (i = 0; *format; format++, i++)
	{
		if (*format != '%')
			write(1, format, 1);
		else
		{
			format++;
			if (*format == '\0')
				break;
			if (*format == 'c')
			{
				c_char = va_arg(input_arg, int);
				write(1, &c_char, 1);
			}
			else if (*format == 's')
			{
				char *s_str = va_arg(input_arg, char*);

				write(1, s_str, strlen(s_str));
				i += strlen(s_str);
			}
			else if (*format == '%')
				write(1, format, 1);
		}
	}
	--i;
	va_end(input_arg);
	return (i);
}
