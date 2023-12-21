#include "shell.h"

/**
 * sys_execute - Executes an external command using fork and execve
 * and waits for its completion.
 * @cmd: An array of strings representing the command and its arguments.
 * @env: An array of t_pair representing the environment variables.
 * @prog: program name
 * Return: The exit status of the executed command or -1 on failure.
 */

static int sys_execute(char **cmd, char **env, char *prog)
{
	int st = 0;

	pid_t pid = fork();

	if (pid == -1)
		return (-1);
	else if (pid == 0)
	{
		if (execve(cmd[0], cmd, env) == -1)
			perror(prog);
		exit(EXIT_FAILURE);
	}
	else
		waitpid(pid, &st, 0);
	return (st);
}

/**
 * _execute - command executer controller
 * @cmd_l: cmd data structure info.
 * @env: A 2d array of t_pair representing the environment variables.
 * @prog: program name
 * @status: status of last execution
 * Return: The exit status of the executed command or -1 on failure.
 */
int _execute(t_cmd *cmd_l, char ***env, char *prog, int status)
{
	int st = 0;
	char **new_env;

	while (cmd_l != NULL)
	{
		st = 0;
		new_env = *env;
		if (!cmd_l->cmd[0])
			;
		else if (_strcmp(cmd_l->cmd[0], "echo") == 0)
			st = ft_echo(cmd_l->cmd, status);
		else if (_strcmp(cmd_l->cmd[0], "exit") == 0)
			st = ft_exit(cmd_l, status, *env);
		else if (_strcmp(cmd_l->cmd[0], "env") == 0)
			st = _env(*env);
		else if (_strcmp(cmd_l->cmd[0], "unsetenv") == 0)
			new_env = unset_env(*env, cmd_l->cmd, prog);
		else if (_strcmp(cmd_l->cmd[0], "setenv") == 0)
			new_env = set_env(*env, cmd_l->cmd, prog);
		else
			st = sys_execute(cmd_l->cmd, *env, prog);
		if (new_env == NULL)
			st = -1;
		else
			*env = new_env;
		if (st != 0 && cmd_l->type == AND)
			break;
		else if (st == 0 && cmd_l->type == OR)
			break;
		cmd_l = cmd_l->next;
		status = st;
	}
	return (st > 255 ? 2 : st);
}
