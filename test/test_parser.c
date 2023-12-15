#include "../shell.h"

int main(int ac, char **av)
{
	t_cmd *cmd;

	if (ac != 2)
		return (printf("Usage: %s arg1 [args...]\n", av[0]));
	printf("command:%s\n", av[1]);
	parse(av[1], &cmd);
	return (0);
}
