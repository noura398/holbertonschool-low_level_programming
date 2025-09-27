#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_numbers - prints numbers separated by a separator, then newline
 * @separator: string printed between numbers (ignored if NULL)
 * @n: number of integers to print
 *
 * Return: void
 */
void print_numbers(const char *separator, const unsigned int n, ...)
{
	va_list ap;
	unsigned int i;

	va_start(ap, n);

	for (i = 0; i < n; i++)
	{
		printf("%d", va_arg(ap, int));
		if (separator && i + 1 < n)
			printf("%s", separator);
	}

	printf("\n");
	va_end(ap);
}
