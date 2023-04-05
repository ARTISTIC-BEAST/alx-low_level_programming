#include "lists.h"

/**
 * delete_nodeint_at_index - deletes the node at index of a listint_t linked list
 * @head: pointer to a pointer to the head of the list
 * @index: index of the node to delete
 *
 * Return: 1 if successful, -1 otherwise
 */
int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	unsigned int i;
	listint_t *current_node = *head, *prev_node = NULL;

	if (*head == NULL)
	return (-1);

	if (index == 0)
	{
	*head = (*head)->next;
	free(current_node);
	return (1);
	}

	for (i = 0; i < index; i++)
	{
	if (current_node == NULL)
	return (-1);

	prev_node = current_node;
	current_node = current_node->next;
	}

	prev_node->next = current_node->next;
	free(current_node);
	return (1);
}

