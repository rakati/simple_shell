#include "shell.h"

/**
 * add_elem - add an element to list if list is empty create new one with the
 * element.
 * @head: pointer to pointer to the list.
 * @val: pointer to element value.
 *
 * Return: a pointer to the head or NULL if an error occurred.
 */
t_list *add_elem(t_list **head, char *val)
{
	t_list *cur, *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->val = val;
	new->next = NULL;
	if (*head == NULL)
		*head = new;
	else
	{
		cur = *head;
		while (cur->next != NULL)
			cur = cur->next;
		cur->next = new;
	}
	return (*head);
}

/**
 * free_list - free the list.
 * @head: pointer to the head of list.
 */
void free_list(t_list *head)
{
	t_list *next;

	while (head)
	{
		next = head->next;
		free(head);
		head = next;
	}
}

/**
 * print_list - print the list.
 * @head: pointer to the head of list.
 */
void print_list(t_list *head)
{
	t_list *next;

	while (head)
	{
		next = head->next;
		_puts(head->val);
		_puts(" => ");
		head = next;
	}
	_puts("\n");
}

/**
 * list_to_arr - convert linked list to a 2d array
 * @head: pointer to the head of list.
 *
 * Return: 2d array of strings
 */
char **list_to_arr(t_list *head)
{
	int c = 0;
	t_list *cur;
	char **arr;

	cur = head;
	while (cur)
	{
		c++;
		cur = cur->next;
	}
	arr = malloc((c + 1) * sizeof(char *));
	if (!arr)
		return (NULL);
	cur = head;
	c = 0;
	while (cur)
	{
		arr[c] = _strdup(cur->val);
		cur = cur->next;
		c++;
	}
	arr[c] = NULL;
	return (arr);
}
