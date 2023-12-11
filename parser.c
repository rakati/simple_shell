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
