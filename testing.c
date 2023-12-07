#include "shell.h"

int main ()
{
	char *line = NULL;
	size_t length = 0;
	ssize_t numberOfBytes = 0;

	printf("Enter something: ");
	numberOfBytes = _getline(&line, &length, stdin);

	if (numberOfBytes != -1)
		printf(" you typed: %s length is:%lu", line, numberOfBytes);
	else
		printf("Error\n");

	free(line);

	return (0);
}
