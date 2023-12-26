#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

/**
 * main - Executes ls -l /tmp in 5 different child processes
 *
 * Return: Always 0
 */
int main(void)
{
	pid_t child_pid;
	int i;

	for (i = 0; i < 5; i++)
	{
		child_pid = fork();

		if (child_pid == -1)
		{
			perror("Error:");
			return (1);
		}
		else if (child_pid == 0)
		{
			char *args[] = {"ls", "-l", "/tmp", NULL};
			execve("/bin/ls", args, NULL);
			perror("Error:");
			return (1);
		}
		else
		{
			wait(NULL);
		}
	}

	return (0);
}

