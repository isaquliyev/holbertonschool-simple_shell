#include <stdio.h>

int main (int ac, char **av)
{
	while (*av)
	{
		if (*(av + 1))
			printf("%s ", *av);
		else
			printf("%s\n", *av);
		av++;
	}
	return (0);
}
