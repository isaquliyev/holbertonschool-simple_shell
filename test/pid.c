#include <stdio.h>
#include <unistd.h>

/**
 * main - PID
 *
 * Return: Always 0.
 */
int main(void)
{
	pid_t my_pid;
	pid_t child_pid;

	my_pid = getppid();
	child_pid = getpid();
	printf("%u\n%u\n", my_pid, child_pid);
	return (0);
}
