#include "shell.h"

int main()
{
	char *line;
	int fd, readed;

	fd = open("testing.txt",O_RDONLY);

	while(1)
	{
		readed = _getline(&line, fd);
		if (readed == -1 || readed == -2)
			exit(EXIT_FAILURE);
		printf("%s\n%d\n", line, readed);
		free(line);
	}

	return (0);
}
