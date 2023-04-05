#include "lists.h"
#include <stdlib.h>

/**
 * free_listint_safe - frees a linked list (safe version)
 *
 * @h: pointer to the pointer to the head node
 *
 * Return: number of nodes freed
 */
size_t free_listint_safe(listint_t **h)
{
	listint_t *current = *h, *next;
	size_t count = 0;

	if (h == NULL)
	return (count);

	while (current != NULL)
	{
	count++;
	next = current->next;
	free(current);

	if (next >= current)
	{
	*h = NULL;
	break;
	}
	current = next;
	}
	*h = NULL;
	return (count);
}


