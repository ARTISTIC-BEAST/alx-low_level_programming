#include "main.h"

/**
 * print_binary - Prints the binary representation of a number.
 * @n: The number to be printed in binary.
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = 1, temp;

	int i, flag = 0;

	for (i = 63; i >= 0; i--)

	{
		temp = n >> i;
		if (temp & mask)

		{
			flag = 1;
			_putchar('1');

		}

		else if (flag == 1 || i == 0)
			_putchar('0');

	}
}

