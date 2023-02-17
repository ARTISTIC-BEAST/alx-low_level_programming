#include <stdlib.h>
#include <time.h>
#include <stdio.h>
/**
 * main - Prints the last digit of a randomly generated number
 * and if it is greater than 5, less than 6, or 0
 * Return: Always 0.
 */
int main(void)
{
	int n;
	int a;

	srand(time(0));
	n = rand() - RAND_MAX / 2;
	a = % 10;

	if (a > 5)
	{
		printf("Last digit of %i is %i and is greater than 5\n", n, a);
	}
	else if (a == 0)
	{
		printf("Last digit of %i is %i and is 0\n", n, a);
	}
	else
	{
		printf("Last digit of %i is %i and is less than 6 and not 0\n", n, a);
	}
	return (0);
}

