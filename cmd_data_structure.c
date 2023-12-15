#include "shell.h"

/**
 * add_cmd - add new cmd to cmd_list if cmd_list is empty create new one
 * with the new cmd.
 *
 * @head: pointer to pointer to the cmd_list.
 * @cmd: array of strings - array of command and its argument, the first
 * string is the command and the next elements are args of the command.
 * @t: type of relationship can be '|', '&', or '\0' refer to enum rel
 * to know more about each type.
 *
 * Return: a pointer to the head or NULL if an error occurred.
 */
t_cmd *add_cmd(t_cmd **head, char **cmd, char t)
{
	t_cmd *cur, *new;

	if (head == NULL)
		return (NULL);
	new = malloc(sizeof(t_cmd));
	new->cmd = cmd;
	new->type = (t == '|' ? OR : (t == '&' ? AND : SEM));
	new->next = NULL;
	if (new == NULL)
		return (NULL);
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
 * free_cmd_list - free the cmd list.
 * @head: pointer to the head of list.
 */
void free_cmd_list(t_cmd *head)
{
	t_cmd *cur, *next;

	cur = head;
	while (cur)
	{
		next = cur->next;
		free_2d_arr(cur->cmd);
		free(cur);
		cur = next;
	}
}

/**
 * print_cmd_list - print the cmd list elements.
 * @head: pointer to the head of list.
 */
void print_cmd_list(t_cmd *head)
{
	int i;

	while (head)
	{
		_puts("cmd:");
		for (i = 0; head->cmd[i]; i++)
		{
			_puts(head->cmd[i]);
			_puts(", ");
		}
		_puts("\n");
		head = head->next;
	}
	_puts("\n");
}

/**
 * free_2d_arr - free a 2d array
 * @arr: array of string.
 */
void free_2d_arr(char **arr)
{
	int i;

	for (i = 0; arr[i]; i++)
		free(arr[i]);
	free(arr);
}
