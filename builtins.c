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
 * Return: return error number only on error otherwise exit with status.
 */

int ft_exit(t_cmd *cmd)
{
	int i, st = 0;

	if (cmd->cmd[1])
	{
		for (i = 0; cmd->cmd[1][i]; i++)
		{
			if (cmd->cmd[1][i] < '0' || cmd->cmd[1][i] > '9')
			{
				write(2, "exit: Illegal number: ", 23);
				write(2, cmd->cmd[1], _strlen(cmd->cmd[1]));
				write(2, "\n", 1);
				return (2);
			}
			st = (st * 10) + (cmd->cmd[1][i] - '0');
		}
	}
	free_cmd_list(cmd);
	exit(st);
	return (0);
}
