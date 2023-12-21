#include "shell.h"

/**
 * _is_cmd_exist - Searches for a command in the PATH environment, if it is
 * exist update the command with its full path.
 * @cmd: address of pointer to command to look for.
 * @env: An array of t_pair representing the environment variables.
 * @prog: program name
 * Return: 0 if found otherwise 2
 */

static int _is_cmd_exist(char **cmd, char **env, char *prog)
{
	char *path = NULL;
	char *tok, *cmd_path;
	int i, l, l2;

	if (access(*cmd, F_OK) == 0)
		return (0);
	for (i = 0; env[i]; i++)
		if (_strncmp(env[i], "PATH", 4) == 0)
		{
			path = _strdup(env[i] + 5);
			break;
		}
	tok = _strtok(path, ":");
	l = _strlen(*cmd) + 2;
	while (tok != NULL)
	{
		l2 = _strlen(tok);
		cmd_path = malloc((l + l2) * sizeof(char));
		if (cmd_path == NULL)
		{
			perror(prog);
			break;
		}
		_strncpy(cmd_path, tok, l2 + 1);
		_strcat(cmd_path, "/");
		_strcat(cmd_path, *cmd);
		if (access(cmd_path, F_OK) == 0)
		{
			free(*cmd);
			free(path);
			*cmd = cmd_path;
			return (0);
		}

		free(cmd_path);
		tok = _strtok(NULL, ":");
	}
	free(path);
	return (2);
}

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
	pid_t pid;

	if (_is_cmd_exist(&cmd[0], env, prog) != 0)
	{
		write(STDERR_FILENO, prog, _strlen(prog));
		write(STDERR_FILENO, ": 1: ", 5);
		write(STDERR_FILENO, cmd[0], _strlen(cmd[0]));
		write(STDERR_FILENO, ": not found\n", 12);
		return (127);
	}
	pid = fork();
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
	return ((char)st);
}
