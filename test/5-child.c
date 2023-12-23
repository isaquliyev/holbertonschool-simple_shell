#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>

int main()
{
	int child_count = 0;
	pid_t current_pid = getpid();
	pid_t pid = current_pid;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};
	int status;

	printf("Parent Process: %u\n\n--------------------\n", getpid());
	while (child_count < 5)
	{
		if (pid != 0)
		{
			wait(&status);
			pid = fork();
		}
		else
		{
			printf("Child Number: %u\n", getpid());
			execve(argv[0], argv, NULL);
			printf("\n");
			exit(31);
		}
		child_count++;
	}

	printf("\n\nCurrent Pid: %u", getpid());
	return (0);
}
