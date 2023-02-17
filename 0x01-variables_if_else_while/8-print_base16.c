#include <stdio.h>

/**
 * main - prints all the numbers of base 16 in lowercase
 * Return: Always 0 (Success)
 */
int main(void)
{
	int d;
	char c;

	d = 0;
	c = 'a';

	while
		(d < 10)
		{
		putchar(d + '0');
		d++;
		}

	while
		(c <= 'f')
		{
		putchar(c);
		c++;
		}

	putchar('\n');

	return (0);
}
