#include "shell.h"

int main ()
{
	char *line = NULL;
	size_t length = 0;
	ssize_t numberOfBytes = 0;
	int fd = STDIN_FILENO;

	numberOfBytes = _getline(&line, &length, fd);

	if (numberOfBytes != -1)
		printf("you typed: %s\nlength is:%lu\n", line, numberOfBytes);
	else
		printf("Error\n");

	free(line);

	return (0);
}
