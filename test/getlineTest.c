#include "shell.h"

int main()
{
	char *line;
	int fd, r;

	fd = open("testing.txt", O_RDONLY);
	while ((r = _getline(&line, fd)) > 0)
	{
		printf("%s\n", line);
		free(line);
	}
	return (0);
}
