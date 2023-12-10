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
 * Return: Upon success, the function returns the number of characters read,
 * excluding the null-terminator. On end of file or error, it returns -1.
 */

int _getline(char **line, const int fd)
{
	static char *rd;
	char buffer[SIZE];
	int pos;

	pos = (rd != NULL) ? (int)(_strchr(rd, '\n') - rd) : -1;

	if (pos >= 0)
	{
		func(*line, &rd, pos);
		return (pos);
	}

	while ((pos = _read(fd, &rd, buffer)) >= 0)
	{
		if (pos > 0 || pos < SIZE)
			break;
	}

	if (pos == -1)
	{
		free(rd);
		return (-1); /*reading Error*/
	}

	pos = (rd != NULL) ? (int)(_strchr(rd, '\n') - rd) : -1;

	if (pos >= 0)
	{
		func(*line, &rd, pos);
		return (pos);
	}

	*line = NULL;
	free(rd);
	return (pos); /*no line found*/
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

	buff[readed] = '\0';
	*rd = (*rd == NULL) ? _strdup(buff) : _strcat(*rd, buff);

	return (readed);
}

/**
 * process_line - Process a line from the existing content and
 * update the pointers.
 * @line: A pointer to a char pointer where the resulting line will be stored.
 * @rd: A pointer to a char pointer representing existing content.
 * @pos: The position of the newline character in the existing content.
 */

void process_line(char **line, char **rd, int pos)
{
	char *tmp;

	*line = malloc((pos + 1) * sizeof(char));
	_strncpy(*line, *rd, pos);
	(*line)[pos] = '\0';

	tmp = *rd;
	*rd = _strdup(*rd + pos + 1);
	free(tmp);
}
