#include "shell.h"

/**
 * print_pair_list - Prints the key-value pairs of the linked list.
 * @head: The head of the linked list.
 */

void print_pair_list(t_pair *head)
{
	t_pair *current;

	current = head;

	while (current != NULL)
	{
		if (current->is_alias)
		{
			_puts(current->key);
			write(1, "='", 2);
			_puts(current->value);
			write(1, "'\n", 2);
		}
		else
		{
			_puts(current->key);
			write(1, "=", 1);
			_puts(current->value);
			write(1, "\n", 1);
		}

		current = current->next;
	}
}

/**
 * add_pair_node - Adds a new node with the specified key and value
 * to the end of the linked list.
 * @head: The head of the linked list.
 * @key: The key to be added.
 * @value: The value associated with the key.
 * @is_alias: Flag indicating whether it's an is_alias (1) or
 * environment variable (0).
 * Return: The updated head of the linked list.
 */

t_pair *add_pair_node(t_pair *head, char *key, char *value, int is_alias)
{
	t_pair *new;
	t_pair *current;

	new = malloc(sizeof(t_pair));
	if (new == NULL)
	{
		write(STDERR_FILENO, "Error: Memory allocation failed", 32);
		return (NULL);
	}

	new->key = _strdup(key);
	if (new->key == NULL)
	{
		write(STDERR_FILENO, "Error: Memory allocation failed", 32);
		free(new);
		return (NULL);
	}

	new->value = _strdup(value);
	if (new->value == NULL)
	{
		write(STDERR_FILENO, "Error: Memory allocation failed", 32);
		free(new->key);
		free(new);
		return (NULL);
	}

	new->is_alias = is_alias;
	new->next = NULL;
	if (head == NULL)
		return (new);

	current = head;
	while (current->next != NULL)
		current = current->next;

	current->next = new;
	return (head);
}

/**
 * remove_pair_node - Removes a pair node with the specified key from
 * the linked list.
 * @head: The head of the linked list.
 * @key: The key of the node to be removed.
 * @is_alias: Flag indicating whether it's an is_alias (1) or
 * environment variable (0).
 * Return: The updated head of the linked list.
 */

t_pair *remove_pair_node(t_pair *head, char *key, int is_alias)
{
	t_pair *current = head;
	t_pair *prev = NULL;

	while (current != NULL)
	{
		if (_strcmp(current->key, key) == 0 && current->is_alias == is_alias)
		{
			if (prev == NULL)
				head = current->next;
			else
				prev->next = current->next;

			free(current->key);
			free(current->value);
			free(current);
			return (head);
		}

		prev = current;
		current = current->next;
	}

	return (head);
}

/**
 * initialize_list - Initializes the linked list using the envp variable
 * passed through main args.
 * @envp: The environment variables passed to the program.
 * Return: The head of the initialized linked list.
 */

t_pair *initialize_pair_list(char *envp[])
{
	t_pair *head = NULL;
	int i = 0;
	char *token;

	while (envp[i] != NULL)
	{
		token = _strtok(envp[i], "=");
		head = add_pair_node(head, token, _strtok(NULL, "="), 0);
		i++;
	}

	return (head);
}

/**
 * free_pairs_list - Frees the memory occupied by the pairs linked list.
 * @head: The head of the pairs linked list.
 */

void free_pairs_list(t_pair *head)
{
	t_pair *current = head;
	t_pair *next;

	while (current != NULL)
	{
		next = current->next;

		free(current->key);
		free(current->value);
		free(current);

		current = next;
	}
}
