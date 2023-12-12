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

	*line = malloc((pos + 1) * sizeof(char));
	if (*line == NULL)
		return (-1);
	_strncpy(*line, *rd, pos);
	(*line)[pos] = '\0';

	tmp = *rd;
	*rd = _strdup(*rd + pos + 1);
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
	static char *rd = NULL;
	char buffer[SIZE];
	int pos;

	pos = _index(rd, '\n');
	if (pos >= 0)
		return (process_line(&*line, &rd, pos) + 1);
	while ((pos = _read(fd, &rd, buffer)) >= 0)
	{
		if (pos == 0) /*this means that we reach the end of file
				   or the user pressed Ctrl+D*/
		{
			free(rd);
			return (-2);
		}
		if (pos > 0 || pos < SIZE)
			break;
	}

	if (pos == -1)
	{
		free(rd);
		return (-1); /*reading Error*/
	}

	pos = _index(rd, '\n');

	if (pos >= 0) /*pos == 0 here means that the newline charcter is found
				at the beginning of the buffer*/
	{
		process_line(&*line, &rd, pos);
		return (pos + 1);
	}

	*line = NULL;
	free(rd);
	return (pos + 1); /*pos here will have a value less thhan 0*/
}

/**
 * _read - read data from a file descriptor and append it to existing content.
 * @fd: The file descriptor from which to read data.
 * @rd: a char pointer representing existing content.
 * @buff: a buffer to store the data read from the file descriptor.
 *
 * Return: Upon success, the function returns the number of bytes read.
 * On error it returns -1.
 */

int _read(int fd, char **rd, char *buff)
{
	int readed = read(fd, buff, SIZE);

	if (readed == -1)
		return (-1); /*reading Error*/
	if (readed > 0)
	{
		buff[readed] = '\0';
		*rd = (*rd == NULL) ? _strdup(buff) : _strcat(*rd, buff);
	}

	return (readed);
}
