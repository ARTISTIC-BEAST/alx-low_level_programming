#include "lists.h"
#include <stdlib.h>
#include <stdio.h>

/**
 * print_listint_safe - prints a listint_t linked list safely
 * @head: points to the head of the list
 *
 * Return the number of nodes in the list
 */

size_t print_listint_safe(const listint_t *head)
{
	const listint_t *slow_ptr = head, *fast_ptr = head;
	size_t count = 0;

	if (head == NULL)
		exit(98);

	while (slow_ptr && fast_ptr && fast_ptr->next)
	{
		slow_ptr = slow_ptr->next;
		fast_ptr = fast_ptr->next;

		if (slow_ptr == fast_ptr)
		{
			printf("-> [%p] %d\n", (void *)slow_ptr, slow_ptr->n);
			exit(98);
		}

		printf("-> [%p] %d\n", (void *)slow_ptr, slow_ptr->n);
		count++;
	}

	if (slow_ptr != NULL)
	{
		printf("-> [%p] %d\n", (void *)slow_ptr, slow_ptr->n);
		count++;
	}

	return (count);

}
