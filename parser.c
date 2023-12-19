#include "shell.h"

/**
 * parse - pase the passed line, collect its info and set them in t_cmd list.
 * the parsing process is divided into steps as follow:
 * - step 1: tokenizing.
 * - step 2: semantic analysis
 * - step 3: collect info and set them into t_cmd data structure.
 *
 * @line: string - contains command line
 * @cmd_l: t_cmd - data structure for storing command info
 * @prog: program name to display in errors.
 * Return: int - indicating status of parse 0 no error, otherwise -1.
 */
int parse(char *line, t_cmd **cmd_l, char *prog)
{
	t_list *cur, *p_cmds = NULL, *p_cmd;
	char *tok, t;
	int st = 0;

	*cmd_l = NULL;
	/* basic syntax analysis*/
	st = syntax_analysis(line, prog);
	if (st != 0)
		return (st);
	tok = _strtok(line, "#");
	/* Parse commands by ';', '||' and '&&' */
	tok = _strtok(tok, "|;&");
	do
		p_cmds = add_elem(&p_cmds, tok);
	while ((tok = _strtok(NULL, "|;&")));
	cur = p_cmds;
	/* Parse sub commands by space*/
	while (cur)
	{
		p_cmd = NULL;
		t = cur->next ? cur->val[_strlen(cur->val) + 1] : '\0';
		tok = _strtok(cur->val, " ");
		do
			p_cmd = add_elem(&p_cmd, tok);
		while ((tok = _strtok(NULL, " ")));
		*cmd_l = add_cmd(cmd_l, list_to_arr(p_cmd), t);
		free_list(p_cmd);
		cur = cur->next;
	}
	free_list(p_cmds);
	return (st);
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

	next = ltrim(str == NULL ? next : str, (char *)delim);
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

/**
 * syntax_analysis - do basic syntax analysis
 * @line: a line of command
 * @prog: program name to display in errors
 *
 * Return: -1 empty command, 0 on check passed, otherwise a positive
 * error number
 */
int syntax_analysis(char *line, char *prog)
{
	int st = 0;

	/* do nothing */
	if (line == NULL || *line == '#')
		st = -1;
	else if (_index("|&", *line) != -1)
	{
		write(STDERR_FILENO, prog, _strlen(prog));
		write(STDERR_FILENO, ": Syntax error", 15);
		st = 2;
	}
	return (st);
}
