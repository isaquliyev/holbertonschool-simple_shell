#include "main.h"

/**
 * main - main function of project
 *
 * Return: always 0
 */

int main(void)
{
	char *my_prompt, **array, *temp, *command, **path;
	int status, i = 0;
	pid_t pid;

	path = pathfinder();
	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisfun$ ");
		my_prompt = _getline();
		if (!my_prompt)
		{
			break;
		}
		array = splitter(my_prompt, " \n\t");
		free(my_prompt);
		if (!*array)
		{
			free(array);
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			command = strdup(array[0]);
			while (path[i])
			{
				execve(array[0], array, NULL);
				temp = strdup(strcat(path[i], command));
				free(array[0]);
				array[0] = strdup(temp);
				free(temp);
				i++;
			}
			printf("No such file or directory\n");
		}
		else
			wait(&status);
		for (i = 0; *(array + i); i++)
			free(*(array + i));
		free(array);
	}
	free(my_prompt);
	return (0);
}
