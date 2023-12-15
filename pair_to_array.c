 #include "shell.h"

/**
 * convert_to_array - Converts a linked list of t_pair structures
 * to a char** array.
 * @list: A pointer to the linked list of t_pair structures.
 *
 * Return: A char** array representing the key=value strings.
 */

char **convert_to_array(t_pair *list)
{
	int count = 0;
	int j, i = 0;
	char **result;
	t_pair *current = list;

	while (current != NULL)
	{
		count++;
		current = current->next;
	}

	result = malloc((count + 1) * sizeof(char *));
	if (result == NULL)
		return (NULL);

	current = list;
	while (current != NULL)
	{
		result[i] = malloc(_strlen(current->key) + _strlen(curent->value) + 2);
		if (result[i] == NULL)
		{
			for (j = 0; result[j] != NULL, j++)
				free(result[j]);
			free(result);
			return (NULL);
		}

		_strcpy(result[i], current->key);
		_strcat(result[i], "=");
		_strcat(result[i], current->value);

		i++;
		current = current->next;
	}

	result[count] = NULL;
	return (result);
}
