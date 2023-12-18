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
