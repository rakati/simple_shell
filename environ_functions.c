#include "shell.h"

/**
 * print_list - Prints the key-value pairs of the linked list.
 * @head: The head of the linked list.
 */

void print_list(t_env *head)
{
	t_env *current;

	current = head;

	while (current != NULL)
	{
		if (current->alias)
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
 * add_Node - Adds a new node with the specified key and value
 * to the end of the linked list.
 * @head: The head of the linked list.
 * @key: The key to be added.
 * @value: The value associated with the key.
 * @alias: Flag indicating whether it's an alias (1) or
 * environment variable (0).
 * Return: The updated head of the linked list.
 */

t_env *add_Node(t_env *head, char *key, char *value, int alias)
{
	t_env *newNode;
	t_env *current;

	newNode = malloc(sizeof(t_env));
	if (newNode == NULL)
	{
		perror("Error: Memory allocation failed");
		return (NULL);
	}

	newNode->key = _strdup(key);
	if (newNode->key == NULL)
	{
		perror("Error: Memory allocation failed");
		free(newNode);
		return (NULL);
	}

	newNode->value = _strdup(value);
	if (newNode->value == NULL)
	{
		perror("Error: Memory allocation failed");
		free(newNode->key);
		free(newNode);
		return (NULL);
	}
	
	newNode->alias = alias;
	newNode->next = NULL;
	if (head == NULL)
		return (newNode);

	current = head;
	while (current->next != NULL)
		current = current->next;

	current->next = newNode;
	return (head);
}

/**
 * remove_Node - Removes a node with the specified key from the linked list.
 * @head: The head of the linked list.
 * @key: The key of the node to be removed.
 * @alias: Flag indicating whether it's an alias (1) or
 * environment variable (0).
 * Return: The updated head of the linked list.
 */

t_env *remove_Node(t_env *head, char *key, int alias)
{
	t_env *current = head;
	t_env *prev = NULL;

	while (current != NULL)
	{
		if (_strcmp(current->key, key) == 0 && current->alias == alias)
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

t_env *initialize_list(char *envp[])
{
	t_env *head = NULL;
	int i = 0;
	char *token;

	while (envp[i] != NULL)
	{
		token = _strtok(envp[i], "=");
		head = add_Node(head, token, _strtok(NULL, "="));
		i++;
	}

	return (head);
}

/**
 * free_list - Frees the memory occupied by the linked list.
 * @head: The head of the linked list.
 */

void free_list(Node *head)
{
	t_env *current = head;
	t_env *next;

	while (current != NULL)
	{
		next = current->next;

		free(current->key);
		free(current->value);
		free(current);

		current = next;
	}
}
