#include "../shell.h"
#include <stdio.h>

int main(int ac, char **av)
{
	char *s, *t;

	if (ac != 3)
	{
		printf("Usage: %s arg\n", av[0]);
		return (1);
	}
	s = av[1];
	t = _strtok(s, av[2]);
	while (t)
	{
		printf("|%s|\n", t);
		t = _strtok(NULL, av[2]);
	}
	printf("finito\n");
	return (0);
}
