#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list.
 * @head: pointer to head of the list
 *
 * Return: the number of nodes in the list
 */
size_t print_listint_safe(const listint_t *head)
{
	int nodes = 0;
	const listint_t *kichwa = head;

	if (head == NULL)
	{
		return (0);
	}
	printf("[%p] %i\n", (void *)head, (*head).n);
	head = (*head).next;
	for (nodes = 0; head != NULL; nodes++)
	{
		if (head < kichwa)
		{
			printf("[%p] %i\n", (void *)head, (*head).n);
		}
		else
		{
			printf("-> [%p] %i\n", (void *)head, (*head).n);
			break;
		}
		head = (*head).next;
		kichwa = (*kichwa).next;
	}
	return (nodes + 1);
}

