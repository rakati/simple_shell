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
	int fd, interactive, st = 0, prev_st;

	fd = (ac != 1 ? open(av[1], O_RDONLY) : STDIN_FILENO);
	/* env = initialize_pair_list(envp); */
	interactive = isatty(STDIN_FILENO);
	while (1)
	{
		prev_st = st;
		if (fd < 3 && interactive)
			_puts("$ ");
		st = _getline(&line, fd);
		if (st < 0)
		{
			perror(av[0]);
			continue;
		}
		if (st != _strlen(line) + 1)
		{
			if (line != NULL)
				free(line);
			break;
		}
		st = parse(line, &info, av[0]);
		if (line != NULL)
			free(line);
		if (st == 0)
			st = _execute(info, envp, av[0], prev_st);
		free_cmd_list(info);
	}
	return (st > 0 ? st : 0);
}
