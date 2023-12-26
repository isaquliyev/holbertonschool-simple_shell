#include "shell.h"

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
    printf ("path: %s\n", path_env); /* check*/
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
	    return full_path;
        }

        free(full_path);
        path_dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}

void handle_errors(const char *message)
{
    perror(message);
    exit(1);
}

