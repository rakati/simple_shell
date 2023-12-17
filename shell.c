#include "shell.h"

/**
 * main - Entry point for our shell program
 *
 * @ac: (integer) number of argument of the program
 * @av: (array of strings) array of parameters of the program with len=ac
 * @envp: (array of strings) array of environment variable path.
 *
 * Return: int 0 for success otherwise error number
 */
int main(int ac, char **av, char **envp)
{
	char *line = NULL;
	t_cmd *info = NULL;
	/* t_pair *env; */
	int fd;
	int r, st;

	fd = (ac != 1 ? open(av[1], O_RDONLY) : STDIN_FILENO);
	/* env = initialize_pair_list(envp); */
	while (1)
	{
		_puts("$ ");
		r = _getline(&line, fd);
		if (r == -2)
		{
			_puts("\n");
			return (0);
		}
		if (r == -1)
		{
			perror(av[0]);
			continue;
		}
		parse(line, &info);
		st = _execute(info, envp, av[0]);
		free(line);
		free_cmd_list(info);
	}
	return (st);
}
