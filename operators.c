#include "shell.h"

/**
 * operators - handle command aand logical operators
 * @line: command line.
 *
 * Return: 1 if there is no operators, otherwise 0..
 */
int operators(char *line)
{
	char *start;
	node_t *commands;
	static int n = 1;

	if (n != 1)
		n++;
	commands = malloc(sizeof(node_t));
	commands->next = malloc(sizeof(node_t));
	commands->str = line;
	commands->next->str = start = line;
	commands->next->next = NULL;
	while (*start != '\n')
	{
		if (_strncmp(start, " #", 2) == 0)
		{
			start[0] = '\0';
			execute(commands, n);
			return (0);
		}
		else if (_strncmp(start, " ; ", 3) == 0)
		{
			start[0] = '\0';
			execute(commands, n);
			commands->next->str = start + 2;
		}
		else if (_strncmp(start, " && ", 4) == 0)
		{
			start[0] = '\0';
			if (!execute(commands, n))
				return (0);
			commands->next->str = start + 3;
		}
		else if (_strncmp(start, " || ", 4) == 0)
		{
			start[0] = '\0';
			if (execute(commands, n))
				return (0);
			commands->next->str = start + 3;
		}
		start++;
	}
	execute(commands, n);
	return (1);
}
