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

	return (s1[i] - s2[i]);
}

/**
 * ltrim - left trim or skip characters in to_skip str and return pointer
 * to the firs character not in to_skip str.
 *
 * @s: string - to trim
 * @to_skip: whitespace characters or any characters to skip.
 *
 * Return: A pointer to the first character in s not in to_skip str, or NULL.
 */
char *ltrim(char *s, char *to_skip)
{
	int i;

	if (s == NULL)
		return (NULL);
	for (i = 0; s[i]; i++)
		if (_index(to_skip, s[i]) == -1)
			return (s + i);
	return (NULL);
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
