#include "main.h"

/**
 * is_digit - checks if a char is a decimal digit
 * @c: character to check
 *
 * Return: 1 if digit, 0 otherwise
 */
static int is_digit(char c)
{
	return (c >= '0' && c <= '9');
}

/**
 * push_digit_neg - append a digit to a negative accumulator
 * @acc: current (non-positive) accumulator
 * @c: digit character to append
 *
 * Return: updated (non-positive) accumulator
 */
static int push_digit_neg(int acc, char c)
{
	return ((acc * 10) - (c - '0'));
}

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the converted integer, or 0 if the string has no digits
 *
 * Description: Accumulates as a negative number to safely handle INT_MIN.
 * Every '-' seen before the first digit toggles sign; '+' is ignored.
 * Parsing stops at the first non-digit after digits start.
 */
int _atoi(char *s)
{
	int i = 0, sign = 1, started = 0, acc = 0;

	while (s[i] != '\0')
	{
		if (!started)
		{
			if (s[i] == '-')
				sign = -sign;
			else if (s[i] == '+')
				;
			else if (is_digit(s[i]))
			{
				started = 1;
				acc = push_digit_neg(acc, s[i]);
			}
		}
		else
		{
			if (is_digit(s[i]))
				acc = push_digit_neg(acc, s[i]);
			else
				break;
		}
		i++;
	}
	if (!started)
		return (0);
	return ((sign > 0) ? -acc : acc);
}
