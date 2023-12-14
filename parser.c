#include "shell.h"

/**
 * parse - pase the passed line, collect its info and set them in t_cmd list.
 * the parsing process is divided into steps as follow:
 * - step 1: tokenizing.
 * - step 2: semantic analysis
 * - step 3: collect info and set them into t_cmd data structure.
 *
 * @line: string - contains command line
 * @cmd: t_cmd - data structure for storing command info
 * Return: int - indicating status of parse 0 no error, otherwise -1.
 */
int parse(char *line, t_cmd **cmd)
{
	/* code here */
}

/**
 * _strtok - breaks a string into a sequence of zero or more nonempty tokens.
 * @str: the string to be tokenized.
 * @delim: a  set  of bytes that delimit the tokens in the parsed string.
 *
 * Return: a pointer to the next token,  or  NULL  if there are no more tokens.
 */
char *_strtok(char *str, const char *delim)
{
	static char *token, *next;
	int i;

	next = ltrim(str != NULL ? str : next, (char *)delim);
	if (next == NULL || *next == '\0')
		return (NULL);
	token = next;
	for (i = 0; token[i]; i++)
		if (_index(delim, token[i]) != -1)
			break;
	next += i + (token[i] != '\0');
	token[i] = '\0';
	return (token);
}
