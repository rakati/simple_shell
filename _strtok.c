#include "shell.h"

/**
 * _strtok - breaks a string into a sequence of zero or more nonempty tokens.
 * @str: the string to be tokenized.
 * @delim: a  set  of bytes that delimit the tokens in the parsed string.
 *
 * Return: a pointer to the next token,  or  NULL  if there are no more tokens.
 */

char *_strtok(char *str, const char *delim)
{
	static char *token, *next;

	if (str != NULL)
	{
		token = str;
		next = str;
	}

	if (next == NULL || *token == '\0')
		return (NULL);

	token = next;
	next = _strpbrk(next, delim);

	if (next != NULL)
	{
		*next = '\0';
		next++;
	}

	return (token);
}
