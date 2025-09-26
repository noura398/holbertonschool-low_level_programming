#include "main.h"
#include <stdlib.h>
#include <limits.h>

/**
 * _calloc - allocates memory for an array and sets it to zero
 * @nmemb: number of elements
 * @size: size of each element in bytes
 *
 * Return: pointer to allocated zero-initialized memory,
 *         or NULL if nmemb or size is 0, on overflow, or on failure
 */
void *_calloc(unsigned int nmemb, unsigned int size)
{
	unsigned int i, total;
	unsigned char *p;

	if (nmemb == 0 || size == 0)
		return (NULL);

	/* overflow check for nmemb * size */
	if (size != 0 && nmemb > UINT_MAX / size)
		return (NULL);

	total = nmemb * size;
	p = (unsigned char *)malloc(total);
	if (p == NULL)
		return (NULL);

	for (i = 0; i < total; i++)
		p[i] = 0;

	return ((void *)p);
}
