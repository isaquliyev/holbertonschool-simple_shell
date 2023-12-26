#include "shell.h"

void handle_errors(const char *message)
{
	perror(message);
	exit(1);
}

void non_interactive(char *filename)
{
	FILE *input_file = fopen(filename, "r");
	if (input_file == NULL)
		handle_errors("Error opening file");

	char *command = NULL;
	size_t len = 0;
	char **tokens;
	pid_t child_pid;

	while (getline(&command, &len, input_file) != -1)
	{
		tokens = tokenize(command);

		if (strcmp(tokens[0], "exit") == 0)
			exit(0);
		else if (strcmp(tokens[0], "env") == 0)
		{
			for (char **env = environ; *env != NULL; env++)
				printf("%s\n", *env);
		}
		else
		{
			char *path = find_in_path(tokens[0]);
			if (path)
			{
				child_pid = fork();
				if (child_pid == 0)
				{
					execve(path, tokens, environ);
					handle_errors("execve");
				}
				else
				{
					wait(NULL);
				}
			}
			else
			{
				printf("%s: command not found\n", tokens[0]);
			}
		}

		free(command);
		free(tokens);
	}
	fclose(input_file);
}

int main(int argc, char **argv)
{
	char *command = NULL;
	size_t len = 0;
	char **tokens;
	pid_t child_pid;

	while (1)
	{
		if (isatty(STDIN_FILENO))
			printf("$ ");

		if (getline(&command, &len, stdin) == -1)
		{
			if (isatty(STDIN_FILENO))
				handle_errors("error");
			break;
		}

		tokens = tokenize(command);

		if (strcmp(tokens[0], "exit") == 0)
			exit(0);
		else if (strcmp(tokens[0], "env") == 0)
		{
			for (char **env = environ; *env != NULL; env++)
				printf("%s\n", *env);
		}
		else
		{
			char *path = find_in_path(tokens[0]);
			if (path)
			{
				child_pid = fork();
				if (child_pid == 0)
				{
					execve(path, tokens, environ);
					perror("execve");
					exit(EXIT_FAILURE);
				}
				else
				{
					wait(NULL);
				}
			}
			else
			{
				printf("%s: command not found\n", tokens[0]);
			}
		}

		free(command);
		free(tokens);
	}

	return 0;
}

char **tokenize(char *command)
{
	int i = 0;
	char **tokens = malloc(sizeof(char *) * MAX_TOKENS);
	char *token = strtok(command, " ");

	while (token != NULL)
	{
		tokens[i++] = token;
		if (i >= MAX_TOKENS)
		{
			perror("Too many tokens");
			exit(1);
		}
		token = strtok(NULL, " ");
	}

	tokens[i] = NULL;
	return tokens;
}

char *find_in_path(char *command)
{
	char *path_env = getenv("PATH");
	printf("path: %s\n", path_env); /* check*/
	char *path_copy = strdup(path_env);
	char *path_dir = strtok(path_copy, ":");

	while (path_dir != NULL)
	{
		char *full_path = malloc(strlen(path_dir) + strlen(command) + 2);
		sprintf(full_path, "%s/%s", path_dir, command);
		printf("check path: %s\n", full_path); /* check*/

		if (access(full_path, X_OK) == 0)
		{
			free(path_copy);
			if (chmod(full_path, S_IRUSR | S_IWUSR |  S_IXUSR | S_IRGRP | S_IXGRP | S_IROTH | S_IXOTH) == -1)
			{
				perror("chmod");
				exit(EXIT_FAILURE);
			}

			char *result_path = strdup(full_path); /*копия*/
			free(full_path);
			return result_path;
		}

		free(full_path);
		path_dir = strtok(NULL, ":");
	}

	free(path_copy);
	return NULL;
}
