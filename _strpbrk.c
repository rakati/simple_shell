#include "shell.h"
/**
 * _strpbrk - locates the first occurrence in the string s of any
 * of the bytes in the string accept.
 * @s: input
 * @accept: input
 * Return: pointer to the byte in s that matches one of the bytes in accept,
 * or NULL if no such byte is found.
 */
char *_strpbrk(char *s, const char *accept)
{
	int i;

	while (*s != '\0')
	{
		for (i = 0; accept[i] != '\0'; i++)
		{
			if (*s == accept[i])
			{
				return (s);
			}
		}
		s++;
	}

	return (NULL);
}
