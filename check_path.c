#include "shell.h"

/**
 * look_in_path - Searches for a command in the PATH environment.
 * @str: The command to look for.
 *
 * Return: A valid path as a string if found, or NULL if not found.
 */

char *look_in_path(char *str)
{
	char *path = env_path();
	char *token, *full_path;

	if (access(str, F_OK) == 0)
		return (_strdup(str));

	token = _strtok(path, ":");
	while (token != NULL)
	{
		full_path = malloc(_strlen(token) + _strlen(str) + 2);
		if (full_path == NULL)
			return (NULL);

		_strcpy(full_path, token);
		_strcat(full_path, "/");
		_strcat(full_path, str);

		if (access(full_path, F_OK) == 0)
			return (full_path);

		free(full_path);
		token = _strtok(NULL, ":");
	}

	return (NULL);
}
