#include "lists.h"
#include <string.h>

/**
 * add_node - adds a new node at the beginning of a list_t list
 * @head: address of the pointer to the head node
 * @str: string to duplicate and store in the new node
 *
 * Return: address of the new element, or NULL on failure
 */
list_t *add_node(list_t **head, const char *str)
{
	list_t *node;
	unsigned int len = 0;
	char *dup;

	if (head == NULL || str == NULL)
		return (NULL);

	dup = strdup(str);
	if (dup == NULL)
		return (NULL);

	while (dup[len] != '\0')
		len++;

	node = malloc(sizeof(list_t));
	if (node == NULL)
	{
		free(dup);
		return (NULL);
	}

	node->str = dup;
	node->len = len;
	node->next = *head;
	*head = node;

	return (node);
}

