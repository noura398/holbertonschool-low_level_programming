#ifndef VARIADIC_FUNCTIONS_H
#define VARIADIC_FUNCTIONS_H

#include <stdarg.h> /* for va_list */

int _putchar(char c);
int sum_them_all(const unsigned int n, ...);
void print_numbers(const char *separator, const unsigned int n, ...);
void print_strings(const char *separator, const unsigned int n, ...);
void print_all(const char * const format, ...);

/**
 * struct spec - maps a format tag to a printer
 * @t: tag character
 * @f: function that prints the corresponding argument from va_list
 */
struct spec
{
	char t;
	void (*f)(va_list);
};

#endif /* VARIADIC_FUNCTIONS_H */
