#include "shell.h"

/**
 * env - print the current environment
 */
void env(void)
{
	int i, j;

	for (i = 0; environ[i]; i++)
	{
		if (_strncmp(environ[i], "_=", 2) == 0)
			continue;
		for (j = 0; environ[i][j]; j++)
		{
			write(1, &environ[i][j], 1);
		}
		write(1, "\n", 1);
	}
}
