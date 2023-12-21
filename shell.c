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
	char *line = NULL, **env;
	t_cmd *info = NULL;
	int fd, interactive, st = 0, cmd_st = 0;

	fd = (ac != 1 ? open(av[1], O_RDONLY) : STDIN_FILENO);
	if (fd == -1)
	{
		perror(av[0]);
		exit(EXIT_FAILURE);
	}
	env = get_new_2d_arr(envp, NULL);
	interactive = isatty(STDIN_FILENO);
	while (1)
	{
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
			cmd_st = _execute(info, &env, av[0], cmd_st);
		free_cmd_list(info);
	}
	free_2d_arr(env);
	return (cmd_st);
}
