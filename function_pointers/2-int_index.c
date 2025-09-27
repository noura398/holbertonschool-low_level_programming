#include "function_pointers.h"

/**
 * int_index - searches for an integer using a comparator
 * @array: pointer to the first element of the array
 * @size: number of elements in the array
 * @cmp: pointer to function used to compare values
 *
 * Return: index of first element for which cmp returns non-zero,
 *         or -1 if no match is found, size <= 0, or on NULL inputs
 */
int int_index(int *array, int size, int (*cmp)(int))
{
	int i;

	if (array == NULL || cmp == NULL || size <= 0)
		return (-1);

	for (i = 0; i < size; i++)
	{
		if (cmp(array[i]) != 0)
			return (i);
	}

	return (-1);
}
