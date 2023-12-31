#include "shell.h"

/**
 * operators - handle command aand logical operators
 * @commands: command line.
 * @st: status.
 *
 * Return: 1 if there is no operators, otherwise 0..
 */
int operators(node_t *commands, int *st)
{
	char *start;
	static int n = 1;

	if (n != 1)
		n++;
	commands->next->str = start = commands->str;
	while (*start != '\n')
	{
		if (_strncmp(start, " #", 2) == 0 || _strncmp(commands->str, "#", 1) == 0)
		{
			start[0] = '\0';
			execute(commands, n, st);
			return (0);
		}
		else if (_strncmp(start, ";", 1) == 0)
		{
			start[0] = '\0';
			execute(commands, n, st);
			commands->next->str = start + 1;
		}
		else if (_strncmp(start, "&&", 2) == 0)
		{
			start[0] = '\0';
			if (execute(commands, n, st))
				return (0);
			commands->next->str = start + 2;
		}
		else if (_strncmp(start, "||", 2) == 0)
		{
			start[0] = '\0';
			if (execute(commands, n, st) == 0)
				return (0);
			commands->next->str = start + 2;
		}
		start++;
	}
	execute(commands, n, st);
	return (1);
}
