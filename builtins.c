#include "shell.h"

/**
 * ft_echo - mimic echo command.
 * @cmd: array of string - contains command and its args
 * @st: status of last execution
 * Return: int - 0 on success, otherwise -1.
 */

int ft_echo(char **cmd, int st)
{
	int i;

	for (i = 1; cmd[i]; i++)
	{
		if (i > 1)
			if (_puts(" ") < 0)
				return (-1);
		if (cmd[i][0] == '$')
			_put_nbr(cmd[i][1] == '$' ? getpid() : st, 1);
		else if (_puts(cmd[i]) < 0)
			return (-1);
	}
	if (_puts("\n") < 0)
		return (-1);
	return (0);
}

/**
 * ft_exit - free memory allocated and exit with status from the shell.
 * @cmd: data structure contain command and it's arguments
 * @st: status of last command
 * @env: environment variables array
 * @prog: program name
 * Return: return error number only on error otherwise exit with status.
 */

int ft_exit(t_cmd *cmd, int st, char **env, char *prog)
{
	int i;

	if (cmd->cmd[1])
	{
		st = 0;
		for (i = 0; cmd->cmd[1][i]; i++)
		{
			if (cmd->cmd[1][i] < '0' || cmd->cmd[1][i] > '9')
			{
				write(STDERR_FILENO, prog, _strlen(prog));
				write(STDERR_FILENO, ": 1: exit: Illegal number: ", 27);
				write(STDERR_FILENO, cmd->cmd[1], _strlen(cmd->cmd[1]));
				write(2, "\n", 1);
				return (2);
			}
			st = (st * 10) + (cmd->cmd[1][i] - '0');
		}
	}
	free_cmd_list(cmd);
	free_2d_arr(env);
	exit((char)st);
	return (0);
}
