#include "shell.h"

ssize_t _getline(char **lineptr, size_t *n, int fd)
{
	char *new_ptr;
	static size_t count = 0;

	if (lineptr == NULL || n == NULL)
		return (-1); /* error indicating invalid arguments */

	if (*lineptr == NULL || *n == 0)
	{
		*n = INIT_SIZE;
		*lineptr = malloc(*n);

		if (*lineptr == NULL)
			return (-1); /* error indicating the failure of malloc */
	}

	while ((count += read(fd, *lineptr + count, INIT_SIZE)) != 0)
	{
		if(count >= *n - 1)
		{
			new_ptr = _realloc(*lineptr, *n, *n * 2);
			if (new_ptr == NULL)
			{
				free(new_ptr);
				return (-1); /* failled to allocate new memory */
			}
			*n *= 2;
			*lineptr = new_ptr;
		}
		if ((*lineptr)[count - 1] == '\n')
			break;
	}
	if (count == 0)
		return (-1); /* file is empty, nothing to read */

	(*lineptr)[count] = '\0';

	return (count);
}
