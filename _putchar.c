#include <unistd.h>

/**
 * _putchar - to print
 * @c: a char
 * Return: the result
 */
int _putchar (char c)
{
	return (write(1, &c, 1));
}
