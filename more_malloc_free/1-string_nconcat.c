#include "main.h"
#include <stdlib.h>

/**
 * string_nconcat - concatenates two strings into newly allocated memory
 * @s1: first string
 * @s2: second string
 * @n:  number of bytes of s2 to include
 *
 * Return: pointer to new string, or NULL on failure
 */
char *string_nconcat(char *s1, char *s2, unsigned int n)
{
	char *out;
	unsigned int len1 = 0, len2 = 0, i, j, total;

	if (s1 == NULL)
		s1 = "";
	if (s2 == NULL)
		s2 = "";

	while (s1[len1] != '\0')
		len1++;
	while (s2[len2] != '\0')
		len2++;

	if (n >= len2)
		n = len2;

	total = len1 + n;

	out = malloc(sizeof(char) * (total + 1));
	if (out == NULL)
		return (NULL);

	for (i = 0; i < len1; i++)
		out[i] = s1[i];

	for (j = 0; j < n; j++)
		out[i + j] = s2[j];

	out[i + j] = '\0';

	return (out);
}
