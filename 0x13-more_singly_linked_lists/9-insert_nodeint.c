#include "lists.h"

/**
 * insert_nodeint_at_index - inserts a new node at a given position
 * @head: double pointer to the head of the list
 * @idx: index of the list where the new node should be added
 * @n: value to set in the new node
 *
 * Return: address of the new node, or NULL if it failed
 */
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n)
{
	listint_t *new_node, *temp;
	unsigned int i;

	if (!head)
	return (NULL);

	if (idx == 0)
	return (add_nodeint(head, n));
	
	temp = *head;
	for (i = 0; temp && i < idx - 1; i++)
	temp = temp->next;

	if (!temp)
	return (NULL);

	new_node = malloc(sizeof(*new_node));
	if (!new_node)
	return (NULL);
	
	new_node->n = n;
	new_node->next = temp->next;
	temp->next = new_node;

	return (new_node);
}

