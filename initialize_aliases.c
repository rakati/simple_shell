#include "shell.h"

/**
 * initialize_aliases - Initializes aliases in the linked list.
 *
 * This function takes an array of alias strings and initializes
 * the linked list with the provided aliases.
 *
 * @aliases: An array of strings representing the aliases.
 * Return: The head of the initialized linked list.
 */

t_pair *initialize_aliases(char *aliases[])
{
	t_pair *head = NULL;
	int i = 0;
	char *token;

	while (aliases[i] != NULL)
	{
		token = _strtok(aliases[i], "=");
		head = add_pair_node(head, token, _strtok(NULL, "="), 1);
		i++;
	}

	return (head);
}
