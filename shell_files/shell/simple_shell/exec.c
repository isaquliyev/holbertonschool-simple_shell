#include <stdio.h>
#include <unistd.h>

int main(void)
{
	char *argv[] = {"/bin/ls", "-l", "/usr/", NULL}, *envp[] = {NULL};

	printf("Before execve\n");
	if (execve(argv[0], argv, envp) == -1)
	{
		perror("error:");
	}
	printf("After execve\n");
	return (0);
}

