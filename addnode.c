#include "shell.h"

/**
 * addnode - adds a new node at the end of a argv_t list.
 * @head: pointer to pointer to the start of node.
 * @str: string to add.
 *
 * Return: the address of the new element, or NULL.
 */
node_t *addnode(node_t **head, const char *str)
{
	node_t *new, *ptr;
	int i;

	new = malloc(sizeof(node_t));
	if (new == NULL)
		return (NULL);

	new->str = _strdup((char *)str);
	new->next = NULL;

	if (*head == NULL)
	{
		*head = new;
		return (new);
	}
	ptr = *head;
	for (i = 0; ptr->next; i++)
		ptr = ptr->next;
	ptr->next = new;
	return (new);
}

/**
 * freenode - free linked list
 * @head: pointer to the first node.
 */
void freenode(node_t *head)
{
	if (head)
	{
		if (head->str)
			free(head->str);
		freenode(head->next);
		free(head);
	}
}
