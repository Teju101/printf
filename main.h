#ifndef MAIN_H
#define MAIN_H
#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>
#include <string.h>

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

                        if (*format == '%')
                        {
                                int c = va_arg(my_list, int);
                                write(1, format, 1);
                                my_print_out++;
                        }
                        if (*format == 'c')
                        {
                                char c = va_arg(my_list, int);
                                write(1, &c, 1);
                                my_print_out++;
                        }
                        if (*format == 's')
                        {
                                char *my_str = va_arg(my_list, char*);
                                write(1, my_str, strlen(my_str));
                                my_print_out = my_print_out + strlen(my_str);
                        }
                }
                format++;
        }
        return (my_print_out);
}

int _printf(const char *format, ...);

#endif
