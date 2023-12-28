#include "main.h"

/**
 * main - main function of project
 *
 * Return: always 0
 */

int main(void)
{
	char *my_prompt;
	char **array = malloc(1);
	int status, num1;
	size_t len = 0;
	pid_t pid;
	char *shell[] = {"./shell", NULL};

	*array = malloc(1);
	if (isatty(STDIN_FILENO))
		printf("#cisfun$ ");
	num1 = getline(&my_prompt, &len, stdin);
	if (num1 == -1)
		exit(31);
	pid = fork();
	if (pid == 0)
	{
		array = splitter(my_prompt, array);
		execve(array[0], array, NULL);
		if (array[0] == NULL)
			exit(99);
		else
			printf("./shell: No such file or directory\n");
		exit(100);
	}
	else
	{
		wait(&status);
		execve(shell[0], shell, NULL);
	}
	return (0);
}
