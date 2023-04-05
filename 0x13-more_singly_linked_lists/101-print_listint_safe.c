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
	const listint_t *temp;
	size_t i, j;
	const listint_t *array[100];

	if (head == NULL)
	exit(98);

	for (i = 0; head != NULL; i++)
	{
	for (j = 0; j < i; j++)
	{
	if (head == array[j])
	{
	printf("-> [%p] %d\n", (void *)head, head->n);
	return (i);
	}
	}
	array[i] = head;
	temp = head;
	head = head->next;
	printf("[%p] %d\n", (void *)temp, temp->n);
	}
	return (i);
}

