#include "hash_tables.h"
#include <string.h>

/**
 * hash_table_set - adds or updates an element in the hash table
 * @ht: pointer to the hash table
 * @key: key string (must not be empty)
 * @value: value string to store (will be duplicated)
 *
 * Return: 1 on success, 0 on failure
 *
 * Notes:
 * - If @key already exists, its value is replaced (old value is freed).
 * - On collision, the new node is inserted at the beginning of the list.
 * - If @value is NULL, it is treated as an empty string.
 */
int hash_table_set(hash_table_t *ht, const char *key, const char *value)
{
	unsigned long int idx;
	hash_node_t *node, *cur;
	char *kdup, *vdup;

	if (ht == NULL || key == NULL || *key == '\0')
		return (0);

	/* duplicate inputs first so we can safely return on failure */
	kdup = strdup(key);
	if (kdup == NULL)
		return (0);

	if (value == NULL)
		vdup = strdup("");
	else
		vdup = strdup(value);

	if (vdup == NULL)
	{
		free(kdup);
		return (0);
	}

	idx = key_index((const unsigned char *)key, ht->size);

	/* check if key already exists: update its value */
	cur = ht->array[idx];
	while (cur != NULL)
	{
		if (strcmp(cur->key, key) == 0)
		{
			free(cur->value);
			cur->value = vdup;
			free(kdup); /* we don't need the duplicated key in update case */
			return (1);
		}
		cur = cur->next;
	}

	/* not found: create a new node and add at head (handle collision) */
	node = malloc(sizeof(hash_node_t));
	if (node == NULL)
	{
		free(kdup);
		free(vdup);
		return (0);
	}

	node->key = kdup;
	node->value = vdup;
	node->next = ht->array[idx];
	ht->array[idx] = node;

	return (1);
}

