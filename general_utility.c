#include "shell.h"

/**
 * _index - Find index of a character in a string
 * @s: string - the source string we try to locate character in
 * @c: char - character to find in the string `s`
 * Return: index of the character inside the string s or -1 if not found
 */
int _index(const char *s, const char c)
{
	int i;

	if (s == NULL)
		return (-1);
	for (i = 0; s[i] != '\0'; i++)
		if (s[i] == c)
			return (i);
	return (-1);
}
