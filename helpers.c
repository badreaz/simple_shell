#include "shell.h"

/**
 * _strdup - copy a string to allocated memory.
 * @str: pointer to string.
 *
 * Return: the pointer to allocated memory, otherwise NULL.
 */
char *_strdup(const char *str)
{
	char *p;
	int size = 0;

	if (str == 0)
		return (0);
	while (str[size] != '\0')
		size++;
	size++;
	p = malloc(sizeof(char) * size);
	if (p == NULL)
		return (NULL);
	size = 0;
	while (str[size] != '\0')
	{
		p[size] = str[size];
		size++;
	}
	p[size] = '\0';
	return (p);
}

/**
 * _strcat - concatenate two strings.
 * @dest: pointer to string.
 * @src: pointer to string.
 *
 * Return: pointer to dest.
 */
char *_strcat(char *dest, char *src)
{
	char *cat = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (cat);
}

/**
 * _strlen - return the length of a string.
 * @s: pointer to char.
 *
 * Return: the length of string.
 */
int _strlen(char *s)
{
	char *p = s;
	int count = 0;

	while (*p != '\0')
	{
		count++;
		p++;
	}
	return (count);
}

/**
 * _strcmp - compare two strings.
 * @s1: string 1.
 * @s2: string 2.
 *
 * Return: int.
 */
int _strcmp(char *s1, char *s2)
{
	int cmp = 0;

	while (cmp == 0)
	{
		if ((*s1 == '\0') && (*s2 == '\0'))
			break;
		cmp = *s1 - *s2;
		s1++;
		s2++;
	}
	return (cmp);
}

/**
 * _strncmp - compare two strings.
 * @s1: string 1.
 * @s2: string 2.
 * @len: length.
 *
 * Return: int.
 */
int _strncmp(char *s1, char *s2, int len)
{
	int cmp = 0, i;

	i = 0;
	while (cmp == 0 && i < len)
	{
		if ((*s1 == '\0') && (*s2 == '\0'))
			break;
		cmp = *s1 - *s2;
		s1++;
		s2++;
		i++;
	}
	return (cmp);
}
