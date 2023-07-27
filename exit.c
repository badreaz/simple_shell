#include "shell.h"

/**
 * myexit - exit the program
 * @line: command line.
 * @mynode: commands and arguments.
 * @n: line number.
 * @st: status.
 */
void myexit(node_t *line, node_t *mynode, int n, int *st)
{
	char *exit_n = "exit", cnum, *name;
	int i = 0, j;

	if (_strcmp(mynode->str, exit_n) == 0)
	{
		if (mynode->next)
		{
			i = _atoi(mynode->next->str);
			for (j = 0; mynode->next->str[j]; j++)
			{
				if (_isdigit(mynode->next->str[j]) == 0)
					i = -1;
			}
			if (i < 0)
			{
				*st = 2;
				cnum = n + '0';
				name = getenv("_");
				for (j = 0; name[j]; j++)
					;
				write(2, "./hsh", j);
				write(2, ": ", 2);
				write(2, &cnum, 1);
				write(2, ": exit: Illegal number: ", 25);
				write(2, mynode->next->str, 10);
				write(2, "\n", 1);
			}
			else if (i > 256)
				*st = i % 256;
			else
				*st = i;
		}
		freenode(line);
		freenode(mynode);
		exit(*st);
	}
}
