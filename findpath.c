#include "shell.h"

/**
 * findpath - find the path of a command
 * @cmd: command.
 *
 * Return: command path, otherwise NULL.
 */
char *findpath(char *cmd)
{
	char *path, *dir, *new;

	if (_which(cmd))
	{
		path = _strdup(getenv("PATH"));
		dir = strtok(path, ":");
		while (dir)
		{
			new = malloc(_strlen(dir) + _strlen(cmd) + 3);
			_strcat(new, dir);
			_strcat(_strcat(new, "/"), cmd);
			if (!_which(new))
			{
				free(path);
				return (new);
			}
			dir = strtok(NULL, ":");
			free(new);
		}
		errno = 127;
		free(path);
		return (NULL);
	}
	return (cmd);
}

/**
 * _which - check if a command exists
 * @path: command path.
 *
 * Return: 0 if true, otherwise -1.
 */
int _which(char *path)
{
	struct stat st;

	if (stat(path, &st) == 0)
	{
		if (S_ISDIR(st.st_mode) || access(path, F_OK | X_OK))
		{
			errno = 126;
			return (-1);
		}
		return (0);
	}
	return (-1);
}
