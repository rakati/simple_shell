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
 * Return: int - indicating status of parse 0 no error, otherwise -1.
 */
int parse(char *line, t_cmd **cmd_l)
{
	t_list *cur, *p_cmds = NULL, *p_cmd;
	char *tok, t;

	*cmd_l = NULL;
	/* Parse commands by ';', '||' and '&&' */
	tok = _strtok(line, "|;&");
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
	return (0);
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
