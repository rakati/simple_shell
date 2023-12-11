#include "shell.h"

/**
 * main - Entry point for our shell program
 *
 * @ac: (integer) number of argument of the program
 * @av: (array of strings) array of parameters of the program with len=ac
 * @envp: (array of strings) array of environment variable path.
 * @return int 0 for success otherwise error number
 */
int main(int ac, char **av, char **envp)
{
	char line;
	int fd;
	int r;

	fd = (ac != 1 ? open(av[1], O_RDONLY) : STDIN_FILENO);
	while (1)
	{
		_puts("$ ");
		r = _getline(fd, &line);
		/* check _getline */
	}
	return (0);
}
