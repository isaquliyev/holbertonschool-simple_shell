#include "main.h"

/**
 * main - entry point
 * Return: 0
 */

int main(void)
{
	char *buf = NULL, *token, *path, **array;
	size_t count = 0;
	ssize_t nread;
	pid_t child_pid;
	int status, i;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			write(STDOUT_FILENO, "#cisfun$ ", 9);
		nread = getline(&buf, &count, stdin);
		if (nread == -1)
			exit(0);
		token = strtok(buf, " \n");
		array = malloc(sizeof(char *) * 1024);
		for (i = 0; token != NULL; i++)
		{
			array[i] = token;
			token = strtok(NULL, " \n");
		}
		array[i] = NULL;
		if (strcmp(array[0], "exit") == 0)
			b_exit();
		if (strcmp(array[0], "env") == 0)
			b_env();
		path = get_file_path(array[0]);
		child_pid = fork();
		if (child_pid == -1)
			exit(41);
		if (child_pid == 0)
		{
			if (execve(path, array, NULL) == -1)
				exit(97);
		}
		else
			wait(&status);
	}
	free(path);
	free(buf);
	return (0);
}

