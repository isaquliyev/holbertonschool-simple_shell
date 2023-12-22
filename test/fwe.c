#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int main()
{
	pid_t current_pid;
	pid_t pid;
	int status;
	char *argv[] = {"/bin/ls", "-l", "/tmp/", NULL};

	current_pid = getpid();
	printf("Current process: %u\n", current_pid);
	pid = fork();
	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
		sleep(1);
	}
	else
	{
		wait(&status);
		printf("I've been waitin on this my whole life\n");
	}
	return (0);
}
