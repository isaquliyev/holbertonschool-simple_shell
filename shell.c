#include "main.h"

/**
 * main - main function of project
 *
 * Return: always 0
 */

int main(void)
{
	char *my_prompt;
	char **array;
	int status, num1;
	size_t len = 0;
	pid_t pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
                printf("#cisfun$ ");
	
	my_prompt = _getline();
	if (!my_prompt)
		break;
	array = splitter(my_prompt);
	free(my_prompt);
	if(!*array)
	{
		free(array);
		continue;
	}
	pid = fork();
	if (pid == 0)
	{
		execvp(array[0], array);
		printf("./shell: No such file or directory\n");
		exit(100);
	}
	else
		wait(&status);
	}
	free(my_prompt);
	return (0);
}
