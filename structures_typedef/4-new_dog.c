#include "dog.h"
#include <stdlib.h>

/**
 * new_dog - creates a new dog and stores copies of name and owner
 * @name: dog's name (string)
 * @age: dog's age
 * @owner: owner's name (string)
 *
 * Return: pointer to new dog_t, or NULL on failure
 */
dog_t *new_dog(char *name, float age, char *owner)
{
	dog_t *d;
	int ln = 0, lo = 0, i;

	if (name == NULL || owner == NULL)
		return (NULL);

	while (name[ln] != '\0')
		ln++;
	while (owner[lo] != '\0')
		lo++;

	d = (dog_t *)malloc(sizeof(dog_t));
	if (d == NULL)
		return (NULL);

	d->name = (char *)malloc(sizeof(char) * (ln + 1));
	if (d->name == NULL)
	{
		free(d);
		return (NULL);
	}

	d->owner = (char *)malloc(sizeof(char) * (lo + 1));
	if (d->owner == NULL)
	{
		free(d->name);
		free(d);
		return (NULL);
	}

	for (i = 0; i < ln; i++)
		d->name[i] = name[i];
	d->name[ln] = '\0';

	for (i = 0; i < lo; i++)
		d->owner[i] = owner[i];
	d->owner[lo] = '\0';

	d->age = age;

	return (d);
}
