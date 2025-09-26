#include "dog.h"
#include <stdlib.h>

/**
 * _strlen - computes the length of a string
 * @s: string
 *
 * Return: length of s
 */
static int _strlen(const char *s)
{
	int len = 0;

	while (s[len] != '\0')
		len++;
	return (len);
}

/**
 * _strdup - duplicates a string into newly allocated memory
 * @src: string to copy
 *
 * Return: pointer to new string, or NULL on failure
 */
static char *_strdup(const char *src)
{
	int i, len = _strlen(src);
	char *dst = malloc(sizeof(char) * (len + 1));

	if (dst == NULL)
		return (NULL);

	for (i = 0; i < len; i++)
		dst[i] = src[i];
	dst[len] = '\0';
	return (dst);
}

/**
 * new_dog - creates a new dog and stores copies of name and owner
 * @name: dog's name (string, must not be NULL)
 * @age: dog's age
 * @owner: owner's name (string, must not be NULL)
 *
 * Return: pointer to new dog_t, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;

	if (name == NULL || owner == NULL)
		return (NULL);

	d = malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	d->name = _strdup(name);
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}

	d->owner = _strdup(owner);
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	d->age = age;
	return (d);
}
