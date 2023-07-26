#include "shell.h"

/**
 * myexit - exit the program
 * @line: command line.
 * @mynode: commands and arguments.
 * @n: line number.
 */
void myexit(node_t *line, node_t *mynode, int n)
{
	char *exit_n = "exit";
	int i = 0;
	
	if (_strcmp(mynode->str, exit_n) == 0)
	{
		if (mynode->next)
		{
			i = _atoi(mynode->next->str);
			if (i < 0)
			{
				i = 2;
				write(1, "Illegal number: ", 17);
				write(1, mynode->next->str, 10);
			}
		}
		freenode(line);
		freenode(mynode);
		exit(i);
	}
}
