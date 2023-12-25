#include "main.h"

/**
 *
 *
 */

char *get_file_path(char *file_name)
{
	char *path = getenv("PATH"), *full_path;

	if (startWithForwardSlash(file_name) &&
			access(file_name, X_OK) == 0)
		return (strdup(file_name));
	if (!path)
        {
                perror("Path not found");
                return(NULL);
        }
	full_path = get_file_loc(path, file_name);
	if (full_path == NULL)
	{
		write(2, file_name, strlen(file_name));
		write(2, ": command not found\n", 19);
		return (NULL);
	}
	return (full_path);
}

/**
 *
 *
 *
 */

char *get_file_loc(char *path, char *file_name)
{
	char *path_copy, *token;
	struct stat file_path;
	char *path_buffer = NULL;

	path_copy = strdup(path);
	token = strtok(path_copy, ":");

	while (token)
	{
		if (path_buffer)
		{
			free(path_buffer);
			path_buffer = NULL;
		}
		path_buffer = malloc(strlen(token) + strlen(file_name) + 2);
		if (!path_buffer)
		{
			perror("Error: memory allocation failed");
			exit(EXIT_FAILURE);
		}
		strcpy(path_buffer, token);
		strcat(path_buffer, "/");
		strcat(path_buffer, file_name);
		strcat(path_buffer, "\0");

		if (stat(path_buffer, &file_path) == 0 && access(path_buffer, X_OK) == 0)
		{
			free(path_copy);
			return (path_buffer);
		}
		token = strtok(NULL, ":");
	}
	free(path_copy);
	if (path_buffer)
		free(path_buffer);
	return (NULL);
}

/**
 *
 *
 *
 */

int startWithForwardSlash(const char *str)
{
	if (str != NULL || str [0] == '/')
		return (1);
	return (0);
}

