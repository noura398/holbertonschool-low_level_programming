#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Return: the integer value
 *
 * Note:
 * We accumulate the result as a NEGATIVE number to safely handle INT_MIN.
 * After parsing, if the sign is positive, we negate once at the end.
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int result = 0;        /* keep result non-positive during accumulation */
	int found_digit = 0;

	/* Scan the whole string */
	while (s[i] != '\0')
	{
		if (s[i] == '-')
		{
			sign = -sign;
		}
		else if (s[i] == '+')
		{
			/* ignore */
		}
		else if (s[i] >= '0' && s[i] <= '9')
		{
			int d = s[i] - '0';

			/*
			 * Accumulate as negative: result = result * 10 - d
			 * This avoids overflow on INT_MIN.
			 */
			result = result * 10 - d;
			found_digit = 1;
		}
		else if (found_digit)
		{
			/* stop at first non-digit after we've started reading digits */
			break;
		}
		i++;
	}

	/* If we never found a digit, return 0 */
	if (!found_digit)
		return (0);

	/* If sign is positive, flip result once (may overflow only if result==INT_MIN and sign==+1, which never happens) */
	return (sign > 0) ? -result : result;
}
