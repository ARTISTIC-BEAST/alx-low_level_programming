#include "main.h"
#include <unistd.h>

/**
 * _putchar - writes the character c o stdout
 * @c: the character to print
 * Return: Always 1 (Susscess)
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
