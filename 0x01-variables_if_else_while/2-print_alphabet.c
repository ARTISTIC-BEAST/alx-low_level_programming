#include <stdio.h>

/**
 * main - Prints the alphabet in lower case.
 * Return: Always 0 (Successful)
 */
int main(void)
{
	char lc;

	for (lc = 'a'; lc <= 'z'; lc++)
	{
		putchar(lc);
	}
	putchar('\n');
	return (0);
}
