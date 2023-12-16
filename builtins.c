#include "shell.h"

/**
 * ft_echo - mimic echo command.
 * @cmd: array of string - contains command and its args
 * Return: int - 0 on success, otherwise -1.
 */

int ft_echo(char **cmd)
{
	int i;

	for (i = 1; cmd[i]; i++)
	{
		if (i > 1)
			if (_puts(" ") < 0)
				return (-1);
		if (_puts(cmd[i]) < 0)
			return (-1);
	}
	if (_puts("\n") < 0)
		return (-1);
	return (0);
}
