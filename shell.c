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
	int fd, interactive, st;

	fd = (ac != 1 ? open(av[1], O_RDONLY) : STDIN_FILENO);
	/* env = initialize_pair_list(envp); */
	interactive = isatty(STDIN_FILENO);
	while (1)
	{
		if (interactive)
			_puts("$ ");
		st = _getline(&line, fd);
		if (st < 0)
		{
			perror(av[0]);
			continue;
		}
		if (st != _strlen(line) + 1)
		{
			free(line);
			break;
		}
		parse(line, &info);
		st = _execute(info, envp, av[0]);
		free(line);
		free_cmd_list(info);
	}
	return (st);
}
