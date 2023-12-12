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

/**
 * _strncpy - copy a string
 * @dest: input value
 * @src: input value
 * @n: input value
 *
 * Return: dest
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t j;

	j = 0;
	while (j < n)
	{
		dest[j] = src[j];
		j++;
		if (src[j - 1] != '\0')
			break;
	}
	while (j < n)
	{
		dest[j] = '\0';
		j++;
	}
	return (dest);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the source string
 * Return: returns a pointer to the duplicated string.
 */
char *_strdup(char *str)
{
	int len, i;
	char *newstr;

	if (str == NULL)
		return (NULL);

	len = _strlen(str);
	newstr = malloc(len * sizeof(char) + 1);

	if (newstr == NULL)
		return (NULL);

	for (i = 0; str[i]; i++)
		newstr[i] = str[i];

	newstr[i] = '\0';

	return (newstr);
}

/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: void
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	while (dest[i] != '\0')
	{
		i++;
	}
	j = 0;
	while (src[j] != '\0')
	{
		dest[i] = src[j];
		i++;
		j++;
	}

	dest[i] = '\0';
	return (dest);
}

/**
 * _strlen - Returns the length of a string.
 * @s: Pointer to the string.
 * Return: Length of the string.
 */
int _strlen(char *s)
{
	int length = 0;

	while (*s != '\0')
	{
		length++;
		s++;
	}
	return (length);
}
