#include <stdio.h>
#include "main.h"

/**
 * main - prints the number of arguments passed into the program
 * @argc: number of arguments
 * @argv: array of arguments (unused)
 *
 * Return: Always 0 (Success)
 */
int main(int argc, char *argv[])
{
	(void)argv; /* suppress unused variable warning */
	printf("%d\n", argc - 1);
	return (0);
}
