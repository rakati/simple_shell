#include "shell.h"

/**
 * _strlen - len of string
 *
 * @s: array of characters
 * Return: len of string otherwise -1 if ptr to string is NULL
 */

int _strlen(char *s)
{
	int i = 0;

	if (!s)
		return (-1);
	while (s[i] != '\0')
		i++;
	return (i);
}
