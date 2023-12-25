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
	int status, i;
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
			execvp(array[0], array);
		else
			wait(&status);
		for (i = 0; *(array + i); i++)
			free(*(array + i));
		free(array);
	}
	free(my_prompt);
	return (0);
}
