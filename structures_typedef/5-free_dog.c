#include "dog.h"
#include <stdlib.h>

/**
 * free_dog - frees a dog_t and its dynamically allocated fields
 * @d: pointer to the dog to free
 *
 * Return: void
 */
void free_dog(dog_t *d)
{
	if (d == NULL)
		return;

	free(d->name);
	free(d->owner);
	free(d);
}
