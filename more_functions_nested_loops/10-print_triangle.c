#include "main.h"

/**
 * print_triangle - prints a triangle made of #
 * @size: the size of the triangle
 *
 * Return: nothing
 */
void print_triangle(int size)
{
	int row, space, hash;

	if (size > 0)
	{
		for (row = 1; row <= size; row++)
		{
			for (space = size - row; space > 0; space--)
				_putchar(' ');
			for (hash = 0; hash < row; hash++)
				_putchar('#');
			_putchar('\n');
		}
	}
	else
	{
		_putchar('\n');
	}
}
