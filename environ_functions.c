#include "shell.h"

/**
 * get_new_2d_arr - copy 2d char array and add val string to the array
 * if it isn't null.
 * @arr: a 2d array of char.
 * @val: simple string to add or null
 * Return: new allocated copy of a 2d char array with val added
 * if it isn't null.
 */

char **get_new_2d_arr(char **arr, char *val)
{
	char **new;
	int i;

	for (i = 0; arr[i]; i++)
		;
	new = malloc(sizeof(char *) * (i + 1 + (val != NULL)));
	for (i = 0; arr[i]; i++)
		new[i] = _strdup(arr[i]);
	if (val != NULL)
		new[i++] = _strdup(val);
	new[i] = NULL;
	return (new);
}

/**
 * set_env - Add new `env_var` with `env_value` or update existing `env_var`
 * variable adding `env_value` to it.
 * @env: a 2d array of environment variables string.
 * @args: 2d char - array of commands include
 * ('setenv', 'env_var', 'env_value')
 * @prog: program name, to display in errors.
 * Return: new allocated copy of a 2d char array with env_var removed or same
 * env it nothing need to change, in case of error NULL returned.
 */
char **set_env(char **env, char **args, char *prog)
{
	int i, l;
	char *new, **new_env, *env_var, *env_value;

	if (args[1] == NULL || args[2] == NULL || args[3] != NULL)
	{
		write(STDERR_FILENO, prog, _strlen(prog));
		write(STDERR_FILENO, ": setenv syntax error\n", 23);
		return (NULL);
	}
	env_var = args[1];
	env_value = args[2];
	l = _strlen(env_var) + _strlen(env_value) + 2;
	new = malloc(sizeof(char) * l);
	if (new == NULL)
		return (NULL);
	for (i = 0; env_var[i]; i++)
		new[i] = env_var[i];
	new[i++] = '=';
	new[i] = '\0';
	_strcat(new, env_value);
	for (i = 0; env[i]; i++)
		if (_strncmp(env_var, env[i], _strlen(env_var)) == 0)
		{
			free(env[i]);
			env[i] = new;
			return (env);
		}
	new_env = get_new_2d_arr(env, new);
	free_2d_arr(env);
	return (new_env);
}

/**
 * unset_env - remove `env_var` from environment variable from env array
 * if it is exist.
 * @env: a 2d array of environment variables string.
 * @args: 2d char - array of commands include ('unsetenv', 'env_var')
 * @prog: program name, to display in errors.
 * Return: new allocated copy of a 2d char array with env_var removed or same
 * env it nothing need to change, in case of error NULL returned.
 */
char **unset_env(char **env, char **args, char *prog)
{
	int i, f = 0;
	char **new, *env_var;

	if (args[1] == NULL || args[2] != NULL)
	{
		write(STDERR_FILENO, prog, _strlen(prog));
		write(STDERR_FILENO, ": unsetenv syntax error\n", 25);
		return (NULL);
	}
	env_var = args[1];
	for (i = 0; env[i]; i++)
		if (_strncmp(env_var, env[i], _strlen(env_var)) == 0)
			f++;
	if (f == 0)
		return (env);
	new = malloc(sizeof(char *) * i);
	if (new == NULL)
		return (NULL);
	f = 0;
	for (i = 0; env[i]; i++)
		if (_strncmp(env_var, env[i], _strlen(env_var)) != 0)
			new[f++] = env[i];
	new[f] = NULL;
	free(env);
	return (new);
}

/**
 * _env - print environment variables
 * @env: a 2d array of environment variables string.
 * Return: 0 on success otherwise an error.
 */
int _env(char **env)
{
	int i;

	for (i = 0; env[i]; i++)
	{
		if (_puts(env[i]) < 0)
			return (-1);
		if (write(STDOUT_FILENO, "\n", 1) < 0)
			return (-1);
	}
	return (0);
}
