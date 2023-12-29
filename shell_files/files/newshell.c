#include "main.h"

void free_memory(char *buf, char **array, char *path);

char **split(char *str, const char *delim)
{
	char **tokens;
	char *token;
	int i = 0;

	tokens = malloc(sizeof(char *) * 1024);
	if (tokens == NULL)
	{
		perror("Allocation failed\n");
		exit(EXIT_FAILURE);
	}
	
	token = strtok(str, delim);
	while (token != NULL)
	{
		tokens[i] = strdup(token);
		if (tokens[i] == NULL)
		{
			perror("Allocation failed\n");
			exit(EXIT_FAILURE);
		}
		token = strtok(NULL, delim);
		i++;
	}
	tokens[i] = NULL;
	return tokens;
}

int main(void)
{
	char *buf = NULL, *path, **array;
	size_t count = 0;
	ssize_t nread;
	pid_t child_pid;
	int status;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("#cisnotfun ");
		nread = getline(&buf, &count, stdin);

		if(nread == -1)
		{
			free_memory(buf, NULL, NULL);
			exit(0);
		}
		array = split(buf, "\n");
		if (array[0] == NULL)
		{
			continue;
		}
		if (strcmp(array[0], "exit") == 0)
		{
			free_memory(buf, array, array[0]);
			b_exit();
		}
		if (strcmp(array[0], "env") == 0)
		{
			b_env();
			free_memory(buf, array, array[0]);
		}
		else
		{
			path = get_file_path(array[0]);
			if (path == NULL)
			{
				free_memory(buf, array, NULL);
				continue;
			}
			child_pid = fork();
			if (child_pid == -1)
			{
				free_memory(buf, array, path ? path : NULL);
				exit(41);
			}
			if (child_pid == 0)
			{
				if (execve(path, array, NULL) == -1)
				{
					free_memory(buf, array, path);
					exit(97);
				}
			}
			else 
			{
				wait(&status);
				free_memory(buf, array, path);
			}
		}
	}
	return (0);
}

void free_memory(char *buf, char **array, char *path)
{
	int i = 0;
	free(buf);
	if (array != NULL)
	{
		while(array[i] != NULL)
		{
			free(array[i]);
			i++;
		}
		free(array);
	}
	free(path);
}

