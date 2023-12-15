#include "shell.h"

/**
 * sys_execute - Executes an external command using fork and execve
 * and waits for its completion.
 * @cmd: An array of strings representing the command and its arguments.
 * @env: An array of t_pair representing the environment variables.
 * Return: The exit status of the executed command or -1 on failure.
 */

int sys_execute(char **cmd, t_pair *env)
{
	pid_t pid = fork();

	if (pid == -1)
	{
		perror("Fork Failed");
		return (-1);
	}
	else if (pid == 0)
	{
		if (execve(cmd[0], cmd, (char * const *)env) == -1)
		{
			perror("Execution failed");
			return (-1);
		}
	}
	else
	{
		int status;

		waitpid(pid, &status, 0);

		return (status);
	}
}
