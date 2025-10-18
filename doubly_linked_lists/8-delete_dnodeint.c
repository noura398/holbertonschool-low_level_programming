#include "lists.h"

/**
 * delete_dnodeint_at_index - deletes the node at a given index in a dlistint_t
 * @head: address of pointer to the head of the list
 * @index: index of the node that should be deleted (starting at 0)
 *
 * Return: 1 if it succeeded, -1 if it failed
 */
int delete_dnodeint_at_index(dlistint_t **head, unsigned int index)
{
	dlistint_t *node;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	/* delete head node */
	if (index == 0)
	{
		node = *head;
		*head = node->next;
		if (*head != NULL)
			(*head)->prev = NULL;
		free(node);
		return (1);
	}

	/* walk to the index-th node */
	node = *head;
	for (i = 0; node != NULL && i < index; i++)
		node = node->next;

	/* index out of range */
	if (node == NULL)
		return (-1);

	/* unlink node from list */
	if (node->prev != NULL)
		node->prev->next = node->next;
	if (node->next != NULL)
		node->next->prev = node->prev;

	free(node);
	return (1);
}

