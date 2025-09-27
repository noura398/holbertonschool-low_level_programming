#include "function_pointers.h"

/**
 * print_name - prints a name using a callback
 * @name: the name string
 * @f: pointer to a function that takes a char * and returns void
 *
 * Return: void
 */
void print_name(char *name, void (*f)(char *))
{
	if (!name || !f)
		return;

	f(name);
}
