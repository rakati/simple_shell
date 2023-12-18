#include "shell.h"

/**
 * _getline - read a line from a file descriptor and allocate memory for it.
 * @fd: the file descriptor from which to read the line.
 * @line: a pointer to a char pointer where the resulting line will be stored.
 *
 * This function reads a line from the specified file descriptor and allocates
 * memory to store the line. The memory for the line should be freed by the
 * caller when it is no longer needed.
 *
 * Return: On success, returns the number of characters read, including
 * delimeter, but not including the null-terminator, or -1 on error.
 */
int _getline(char **line, const int fd)
{
	static char buff[BUFF_SIZE + 1] = {0};
	int n, r, l;

	if (line == NULL)
		return (-1);
	*line = NULL;
	n = _index(buff, '\n');
	l = (n != -1 ? n : _strlen(buff));
	if (n != -1)
		buff[n] = '\0';
	*line = _strndup(buff, l);
	while ((n == -1) && (r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		n = _index(buff, '\n');
		l += (n != -1) ? n : r;
		if (n != -1)
			buff[n] = '\0';
		*line = _realloc(*line, l + 1);
		*line = _strcat(*line + l - (n != -1 ? n : r), buff);
		if (r < BUFF_SIZE)
			break;
	}
	if (r < 0)
		return (-1);
	_strncpy(buff, buff + (n != -1 ? n + 1 : BUFF_SIZE), BUFF_SIZE + 1);
	return (l + (n != -1));
}
