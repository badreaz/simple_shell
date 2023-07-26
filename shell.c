#include "shell.h"

/**
 * main - mini shell
 *
 * Return: 0 .
 */
int main(void)
{
	size_t n = 1024;
	char *buffer;
	char eof;

	signal(SIGINT, _sigint);
	buffer = malloc(n);
	errno = 0;
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");
		eof = getline(&buffer, &n, stdin); /* read the line from stdin*/
		if (eof == EOF)  /*check the end of a file*/
			exit(EXIT_SUCCESS);
		operators(buffer);
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
