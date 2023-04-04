#include "lists.h"

/**
 * pop_listint -deletes the head node of a listint_t linked list
 * @head: double pointer to the head of the list
 *
 * Return: the head node's data (n), or 0 if the list is empty
 */

int pop_listint(listint_t **head)

{
	int n;
	listint_t *current_node;

	if (head == NULL || *head == NULL)
		return (0);

	current_node = *head;
	n = current_node->n;

	*head = current_node->next;
	free(current_node);

	return (n);

}

