#include "shell.h"

/**
 * main - mini shell
 * @argc: argument counter.
 * @argv: argument variable.
 *
 * Return: 0 .
 */
int main(int argc, char *argv[])
{
	size_t n = 1024;
	node_t *commands;
	char eof;
	FILE *file = stdin;
	int st = 0;

	signal(SIGINT, _sigint);
	if (argc > 1)
	{
		file = fopen(argv[1], "r");
		if (file == NULL)
		{
			write(2, "./hsh: 0: Can't open", 20);
			write(2, argv[1], 20);
			write(2, "\n", 1);
			exit(127);
		}
	}
	commands = malloc(sizeof(node_t));
	commands->next = malloc(sizeof(node_t));
	commands->str = malloc(n);
	commands->next->next = NULL;
	while (1)
	{
		if (isatty(STDIN_FILENO) && argc == 1)
			printf("$ ");
		eof = getline(&commands->str, &n, file); /* read the line from stdin*/
		if (eof == EOF)  /*check the end of a file*/
		{
			fclose(file);
			freenode(commands);
			exit(st);
		}
		operators(commands, &st);
	}
	return (0);
}

/**
 * _sigint - handle SIGINT signal
 * @sign: signal.
 */
void _sigint(__attribute__((unused)) int sign)
{
	write(1, "\n$ ", 3);
}
