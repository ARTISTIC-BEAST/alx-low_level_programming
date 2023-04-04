#include "lists.h"

/**
 * get_nodeint_at_index - returns the nth node of alistint_t linked list
 * @head: points to the head of the list
 * @index: index of the node, starting at 0
 *
 * Return: pointer to the nth node, or NULL if it does not exist
 *
 */

listint_t *get_nodeint_at_index(listint_t *head, unsigned int index)

{
	unsigned int i;
	listint_t *current_node;

	if (head == NULL)
		return (NULL);

	current_node = head;
	for (i = 0; i < index && current_node != NULL; i++)

	{
		current_node = current_node->next;
	}

	if (i == index && current_node != NULL)
		return (current_node);
	else
		return (NULL);

}
