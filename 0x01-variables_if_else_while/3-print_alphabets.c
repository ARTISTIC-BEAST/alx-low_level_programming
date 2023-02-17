#include <stdio.h>
/**
 * main - Print the alphabet in lower case and in the uppercase.
 * Return: Always 0 (Success)
 */
int main(void)
{
	char c;
	char d;

	c = 'a';
	d = 'A';

	while (c <= 'z')
	{
		putchar(c);
		c++;
	}

	while (d <= 'Z')
	{
		putchar(d);
		d++;
	}

	putchar('\n');

	return (0);
}
