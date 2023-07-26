#include "shell.h"

/**
 * tokenize - tokenize a line using strtok
 * @line: command line.
 * @mynode: linked list.
 *
 * Return: tokenized linked list.*
 */
void tokenize(char *line, node_t **mynode)
{
	char *ptr;

	ptr = strtok(line, " \n");
	while (ptr)
	{
		addnode(mynode, ptr);
		ptr = strtok(NULL, " \n");
	}
}
