#include "main.h"

/**
 * _atoi - converts a string to an integer
 * @s: the string to convert
 *
 * Description:
 * - Skips any characters until a digit is found.
 * - Each '-' seen before the first digit toggles the sign; '+' is ignored.
 * - Once digit parsing starts, it stops at the first non-digit.
 * - Accumulates the number as a NEGATIVE value to safely handle INT_MIN
 *   under -fsanitize=signed-integer-overflow.
 *
 * Return: the converted integer, or 0 if the string contains no digits
 */
int _atoi(char *s)
{
	int i = 0;
	int sign = 1;
	int started = 0; /* whether we've started parsing digits */
	int acc = 0;     /* keep accumulator non-positive while parsing */

	while (s[i] != '\0')
	{
		if (!started)
		{
			if (s[i] == '-')
			{
				sign = -sign;
			}
			else if (s[i] == '+')
			{
				/* ignore '+' before digits */
			}
			else if (s[i] >= '0' && s[i] <= '9')
			{
				started = 1;
				acc = acc * 10 - (s[i] - '0'); /* remain <= 0 */
			}
			/* any other characters before digits: ignore */
		}
		else
		{
			if (s[i] >= '0' && s[i] <= '9')
			{
				acc = acc * 10 - (s[i] - '0'); /* remain <= 0 */
			}
			else
			{
				break; /* stop at first non-digit after starting */
			}
		}
		i++;
	}

	if (!started)
		return (0);

	/* If positive, flip once. INT_MIN is returned directly when sign < 0. */
	return ((sign > 0) ? -acc : acc);
}
