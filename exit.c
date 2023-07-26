#include "shell.h"

/**
 * myexit - exit the program
 * @line: command line.
 * @mynode: commands and arguments.
 * @n: line number.
 */
void myexit(node_t *line, node_t *mynode, int n)
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
				i = 2;
				cnum = n + '0';
				name = getenv("_");
				for (j = 0; name[j]; j++)
					;
				write(1, name, j);
				write(1, ": ", 2);
				write(1, &cnum, 1);
				write(1, ": ", 2);
				write(1, "Illegal number: ", 17);
				write(1, mynode->next->str, 10);
				write(1, "\n", 1);
			}
			i = i % 256;
		}
		freenode(line);
		freenode(mynode);
		exit(i);
	}
}
