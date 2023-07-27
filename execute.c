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
	char **list, *cmd;
	pid_t pid;
	int status;
	node_t *mynode;

	mynode = NULL;
	tokenize(line->next->str, &mynode);
	line->next->str = NULL;
	if (!mynode)
		return (0);
	myexit(line, mynode, n);
	if (_strcmp(mynode->str, "env") == 0)
	{
		env();
		return (0);
	}
	cmd = findpath(mynode->str);
	if (cmd == NULL)
	{
		_perror(n, mynode->str);
		freenode(mynode);
		return (-1);
	}
	list = nodetolist(&mynode);
	pid = fork();
	if (pid == 0)
	{
		execve(cmd, list, environ);
		free(cmd);
		freenode(line);
		freenode(mynode);
		freelist(list);
		exit(EXIT_FAILURE);
	}
	wait(&status);
	free(cmd);
	freenode(mynode);
	freelist(list);
	return (WEXITSTATUS(status));
}

/**
 * _perror - print error to the stdout
 * @ac: line number.
 * @cmd: command.
 */
void _perror(char ac, char *cmd)
{
	char *name;
	int i;

	ac = ac + '0';
	name = getenv("_");
	for (i = 0; name[i]; i++)
		;
	write(2, name, i);
	write(2, ": ", 2);
	write(2, &ac, 1);
	write(2, ": ", 2);
	perror(cmd);
}
