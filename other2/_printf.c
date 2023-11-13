#include "main.h"

/**
 * _printf - the function
 * @format: a constant character
 * Return: The argument inside the function
 */
int _printf(const char *format, ...)
{
	va_list my_list;
	int my_print_out = 0;

	if (format == NULL)
		return (-1);
	va_start(my_list, format);
	while (*format)
	{
		if (*format != '%')
		{
			write(1, format, 1);
			my_print_out++;
		}
		else
		{
			format++;
			if (*format == '\0')
				continue;
			if (*format == '%')
			{
				write(1, format, 1);
				my_print_out++;
			}
			else if (*format == 'c')
			{
				char c = va_arg(my_list, int);

				write(1, &c, 1);
				my_print_out++;
			}
			else if (*format == 's')
			{
				char *my_str = va_arg(my_list, char*);

				int str_len = 0;
				while (my_str[str_len] != '\0')
					str_len++;
				write(1, my_str, str_len);
				my_print_out += str_len;
			}
			else if (*format == 'd')
			{
				int d = va_arg(my_list, int);
				my_putchar(d);
				my_print_out++;
			}
		}
		format++;
	}
	va_end(my_list);
	return (my_print_out);
}
