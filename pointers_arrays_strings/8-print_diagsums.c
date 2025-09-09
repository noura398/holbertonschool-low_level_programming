#include "main.h"
#include <stdio.h>

/**
 * print_diagsums - prints the sum of the two diagonals of a square matrix
 * @a: pointer to the first element of the matrix (flattened)
 * @size: the number of rows/columns in the square matrix
 *
 * Return: void
 */
void print_diagsums(int *a, int size)
{
	int i;
	long primary = 0;
	long secondary = 0;

	for (i = 0; i < size; i++)
	{
		/* index of a[i][i] in flat array is (i * size + i) */
		primary += a[i * size + i];

		/* index of a[i][size - 1 - i] is (i * size + (size - 1 - i)) */
		secondary += a[i * size + (size - 1 - i)];
	}

	printf("%ld, %ld\n", primary, secondary);
}
