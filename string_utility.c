#include "shell.h"

/**
 * _strlen - len of string
 *
 * @s: array of characters
 * Return: len of string otherwise -1 if ptr to string is NULL
 */

int _strlen(const char *s)
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

int _puts(char *s)
{
	int len;

	len = _strlen(s);
	if (len >= 0)
		len = write(1, s, len);
	return (len);
}

/**
 * _strncpy - copies at most n bytes from the string pointed to by src,
 * including the terminating null byte, to the buffer pointed to by dest.
 *
 * If the length of src is less than n, the function writes additional null
 * bytes to dest to ensure that a total of n bytes are written.
 * @dest: input value
 * @src: input value
 * @n: input value
 *
 * Return: A pointer to the destination string dest.
 */
char *_strncpy(char *dest, const char *src, size_t n)
{
	size_t j;

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
