#include "main.h"

/**
 * _printf - Entry point
 * @format: a constant char
 * Return: the result
 */
int _printf(const char *format, ...)
{
	unsigned int i, s_count, count = 0;

	va_list args;

	va_start(args, format);
	
	for (i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			putchr(format[i]);
		}
		else if (format[i + 1] == 'c')
		{
			putchr(va_arg(args, int));
			i++;
		}
		else if (format[i + 1] == 's')
		{
			s_count = putss(va_arg(args, char *));
			i++;
			count += (s_count -1);
		}
		else if (format[i + 1] == '%')
		{
			putchr('%');
		}
		count++;
	}

	va_end(args);
	return (count);
}
