#include "main.h"

/**
 * putchr - print a char
 * @c: char input
 * Return: 1
 */
int putchr(char c)
{
	return (write(1, &c, 1));
}
