#include "shell.h"

/**
 * process_line - Process a line from the existing content and
 * update the pointers.
 * @line: A pointer to a char pointer where the resulting line will be stored.
 * @rd: A pointer to a char pointer representing existing content.
 * @pos: The position of the newline character in the existing content.
 *
 * Return: line length or negative number represent error code
 */
static int process_line(char **line, char **rd, int pos)
{
	char *tmp;

	if (pos < 0)
		return (-1);
	*line = malloc(pos + 1);
	if (*line == NULL)
		return (-2);
	*line = _strncpy(*line, *rd, pos);
	if (*line == NULL)
		return (-2);
	(*line)[pos] = '\0';
	if ((*rd)[pos + 1] == '\0')
	{
		free(*rd);
		*rd = NULL;
		return (pos);
	}
	tmp = *rd;
	*rd = _strdup(*rd + pos + 1);
	if (*rd == NULL)
		return (-2);
	free(tmp);
	return (pos);
}

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
	static char *rd;
	char buff[BUFF_SIZE];
	int pos, r;

	*line = NULL;
	pos = _index(rd, '\n');
	if (pos >= 0)
		return (process_line(line, &rd, pos) + 1);
	while ((r = read(fd, buff, BUFF_SIZE)) > 0)
	{
		buff[r] = '\0';
		if (rd == NULL)
			rd = _strdup(buff);
		else
			rd = _strcat(_realloc(rd, _strlen(rd) + r + 1), buff);
		pos = _index(rd, '\n');
		if (pos >= 0 || r < BUFF_SIZE)
			break;
	}
	if (r != -1)
		return (process_line(line, &rd, pos >= 0 ? pos : _strlen(rd)) + 1);
	if (rd != NULL)
		free(rd);
	return (-1);
}
