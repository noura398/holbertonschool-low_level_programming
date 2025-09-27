#include "variadic_functions.h"
#include <stdarg.h>
#include <stdio.h>

/**
 * print_char - prints a char from va_list
 * @ap: argument list
 */
static void print_char(va_list ap)
{
	printf("%c", va_arg(ap, int));
}

/**
 * print_int - prints an int from va_list
 * @ap: argument list
 */
static void print_int(va_list ap)
{
	printf("%d", va_arg(ap, int));
}

/**
 * print_float - prints a float (as double) from va_list
 * @ap: argument list
 */
static void print_float(va_list ap)
{
	printf("%f", va_arg(ap, double));
}

/**
 * print_string - prints a string from va_list (or (nil))
 * @ap: argument list
 */
static void print_string(va_list ap)
{
	char *s = va_arg(ap, char *);

	if (s == NULL)
		s = "(nil)";
	printf("%s", s);
}

/**
 * print_all - prints anything based on a format string
 * @format: list of types: 'c', 'i', 'f', 's'
 */
void print_all(const char * const format, ...)
{
	char tags[] = {'c', 'i', 'f', 's', '\0'};
	void (*funcs[])(va_list) = {
		print_char, print_int, print_float, print_string, NULL
	};
	va_list ap;
	unsigned int i = 0, j;
	char *sep = "";

	va_start(ap, format);
	while (format && format[i])
	{
		j = 0;
		while (tags[j])
		{
			if (tags[j] == format[i])
			{
				printf("%s", sep);
				funcs[j](ap);
				sep = ", ";
				break;
			}
			j++;
		}
		i++;
	}
	printf("\n");
	va_end(ap);
}

