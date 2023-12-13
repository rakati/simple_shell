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
 * _realloc - resize of the memory block pointed to by ptr to size.
 * The contents will be unchanged in the range from the start of the region
 * up to the minimum of the old and new sizes.
 * @ptr: void ptr - pointer to memory bloc to resize.
 * @size: positive integer - the new memory size for the ptr.
 * Return: pointer to the new memory resized or NULL if an error occurred.
 */
void *_realloc(void *ptr, size_t size)
{
	char *new_ptr, *p;
	size_t i;

	p = (char *)ptr;
	new_ptr = size == 0 ? NULL : malloc(size);
	if (ptr == NULL)
		return (new_ptr);
	for (i = 0; p[i] && i < size; i++)
		new_ptr[i] = p[i];
	new_ptr[i] = p[i];
	free(ptr);
	return (new_ptr);
}
