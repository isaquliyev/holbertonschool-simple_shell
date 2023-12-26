#include <stdio.h>

int main(int ac, char **av, char **envp)
{
	extern char **environ;
	{
		printf("Address of env: %p\n", envp);
		printf("ADdress of environ: %p\n", environ);
	}
	return (0);
}

