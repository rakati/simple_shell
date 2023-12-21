#include "shell.h"

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the string given as a parameter.
 * @str: the source string
 * Return: returns a pointer to the duplicated string.
 */
char *_strdup(const char *str)
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
 * _strndup - Copy up to n bytes from source string into new memory
 * @str: string to copy from.
 * @len: Number of characters to copy
 * Return: returns a pointer to a memory copy.
 */
char *_strndup(const char *str, size_t len)
{
	size_t i;
	char *newstr;

	if (str == NULL)
		return (NULL);

	newstr = malloc(len * sizeof(char) + 1);
	if (newstr == NULL)
		return (NULL);

	for (i = 0; i < len && str[i]; i++)
		newstr[i] = str[i];

	newstr[i] = '\0';
	return (newstr);
}

/**
 * _strncmp - compare n characters of two string
 * @s1: input string
 * @s2: input string
 * @n: number of characters to compare
 *
 * Return: 0 if n char of string are identical, otherwise ascii difference.
 */

int _strncmp(char *s1, char *s2, size_t n)
{
	size_t i = 0;

	while (s1[i] != '\0' && s2[i] != '\0' && i < n)
	{
		if (s1[i] != s2[i])
		{
			return (s1[i] - s2[i]);
		}
		i++;
	}

	return (s1[i] - s2[i]);
}

/**
 * _strcat - concatenates two strings
 * @dest: input value
 * @src: input value
 *
 * Return: pointer to dest string
 */
char *_strcat(char *dest, char *src)
{
	int i;
	int j;

	i = 0;
	if (dest == NULL)
		return (NULL);
	while (dest[i] != '\0')
		i++;

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
