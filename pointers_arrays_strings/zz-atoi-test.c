#include "main.h"
#include <stdio.h>

int main(void)
{
	printf("%d\n", _atoi("4"));                                           /* 4 */
	printf("%d\n", _atoi("10"));                                          /* 10 */
	printf("%d\n", _atoi("-3"));                                          /* -3 */
	printf("%d\n", _atoi("99"));                                          /* 99 */
	printf("%d\n", _atoi("-40"));                                         /* -40 */
	printf("%d\n", _atoi("          ------++++++-----+++++--98"));        /* -98 */
	printf("%d\n", _atoi("Hello ----- world\n"));                          /* 0 (no number) */
	printf("%d\n", _atoi("+++++ +-+ 2242454"));                           /* sign from '-' -> -2242454 */
	printf("%d\n", _atoi("2147483647"));                                  /* 2147483647 (INT_MAX) */
	printf("%d\n", _atoi(" + + - -98 Battery Street; San Francisco, CA 94111 - USA ")); /* 98 */
	printf("%d\n", _atoi("---++++ -++ Sui - te - 402 #cisfun :)"));       /* 402 */
	printf("%d\n", _atoi(""));                                            /* 0 (empty) */
	printf("%d\n", _atoi("-2147483648"));                                 /* -2147483648 (INT_MIN) */
	return (0);
}

