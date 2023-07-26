#include "shell.h"

/**
 * execute - execute commands with it's argument
 * @line: linked list of commands.
 * @n: line number.
 *
 * Return: 0 if true, otherwise -1.
 */
int execute(node_t *line, int n)
{
	char **list, *cmd, *exit_n = "exit";
	pid_t pid;
	int status;
	node_t *mynode;

	mynode = NULL;
	tokenize(line->next->str, &mynode);
	if (!mynode)
		return (0);
	if (_strcmp(mynode->str, exit_n) == 0)
	{
		line->next->str = NULL;
		freenode(line);
		freenode(mynode);
		exit(errno);
	}
	else if (_strcmp(mynode->str, "env") == 0)
	{
		env();
		return (0);
	}
	cmd = findpath(mynode->str);
	if (cmd == NULL)
	{
		write(1, ": ", 2);
		write(1, &n, 3);
		write(1, ": ", 2);
		perror(mynode->str);
		freenode(mynode);
		return (-1);
	}
	list = nodetolist(&mynode);
	pid = fork();
	if (pid == 0)
	{
		execve(cmd, list, environ);
		free(cmd);
		line->next->str = NULL;
		freenode(line);
		freenode(mynode);
		freelist(list);
		exit(EXIT_FAILURE);
	}
	wait(&status);
	free(cmd);
	freenode(mynode);
	freelist(list);
	if (!WIFEXITED(status))
		return (-1);
	return (0);
}
