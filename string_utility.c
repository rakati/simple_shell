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

/**
 * _puts - print string to stdout at once.
 *
 * @s: array of characters
 * Return: Number of character printed, otherwise -1 if an error occurred
 */

void _puts(char *s)
{
	int len;

	len = _strlen(s);
	if (len >= 0)
		len = write(1, s, len);
	return (len);
}

/**
 * _strcmp - compare two string
 * @s1: input string
 * @s2: input string
 *
 * Return: s1[i] - s2[i]
 */

int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] != '\0' && s2[i] != '\0')
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}
	return (0);
}
