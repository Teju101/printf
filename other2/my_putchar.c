#include "main.h"


int my_putchar(char c)
{
	return (write(1, &c, 1));
}
int main(void)
{
	my_putchar('7');
	return (0);
}
