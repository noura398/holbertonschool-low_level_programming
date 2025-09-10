#include "main.h"

/**
 * helper_sqrt - helps to find natural square root
 * @n: number to find square root of
 * @i: possible root
 *
 * Return: square root or -1 if none
 */
int helper_sqrt(int n, int i)
{
	if (i * i == n)
		return (i);
	if (i * i > n)
		return (-1);
	return (helper_sqrt(n, i + 1));
}

/**
 * _sqrt_recursion - returns the natural square root of a number
 * @n: number to calculate square root
 *
 * Return: natural square root, or -1 if not found
 */
int _sqrt_recursion(int n)
{
	if (n < 0)
		return (-1);
	return (helper_sqrt(n, 0));
}
