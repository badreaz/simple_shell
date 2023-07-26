#include "shell.h"

/**
 * _atoi - convert a string to an integer.
 * @s: pointer to a string.
 *
 * Return: integer.
 */
int _atoi(char *s)
{
	int  m = 1, i = 0;
	unsigned int num = 0;

	while ((s[i] < 48 || s[i] > 57) && s[i] != '\0')
	{
		if (s[i] == '-')
			m *= -1;
		i++;
	}
	while ((s[i] > 47 && s[i] < 58) && s[i] != '\0')
	{
		num *= 10;
		num += s[i] - '0';
		i++;
	}

	return (num * m);
}
