#include "shell.h"

/**
 * _strchr - Entry point
 * @s: input
 * @c: input
 * Return: Always 0 (Success)
 */
int _strchr(char *s, char c)
{
	int i = 0;

	if (s == NULL)
		return (-1);

	for (; s[i] >= '\0'; i++)
	{
		if (s[i] == c)
			return (i);
	}
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
char *_strncpy(char *dest, char *src, int n)
{
	int j;

	j = 0;
	while (j < n && src[j] != '\0')
	{
		dest[j] = src[j];
		j++;
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

	for (i = 0; str[i] ; i++)
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
