#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 20

char *find_in_path(char *command) {
    char *path_env = getenv("PATH");
    char *path_copy = strdup(path_env);
    char *path_dir = strtok(path_copy, ":");
    char *full_path;

    while (path_dir != NULL) {
        full_path = malloc(strlen(path_dir) + strlen(command) + 2);
        sprintf(full_path, "%s/%s", path_dir, command);

        if (access(full_path, X_OK) == 0) {
            free(path_copy);
            return full_path;
        }

        free(full_path);
        path_dir = strtok(NULL, ":");
    }

    free(path_copy);
    return NULL;
}

int main(void) {
    char *input = NULL;
    size_t len = 0;
    ssize_t read;
    pid_t child_pid;
    char *args[MAX_ARGS], *token, *path;
    int argc;

    while (1) {
        argc = 0;
        printf("$ ");
        fflush(stdout);

        read = getline(&input, &len, stdin);
        if (read == -1) {
		if (feof(stdin))
		{
			printf("\n");
			break;
		}
		else
		{
            	perror("getline");
            	exit(EXIT_FAILURE);
		}
        }

        input[strcspn(input, "\n")] = '\0';

        token = strtok(input, " ");
        while (token != NULL && argc < MAX_ARGS - 1) {
            args[argc++] = token;
            token = strtok(NULL, " ");
        }
        args[argc] = NULL;

        path = find_in_path(args[0]);
        if (path != NULL) {
            child_pid = fork();
            if (child_pid == -1) {
                perror("fork");
                exit(EXIT_FAILURE);
            }

            if (child_pid == 0) {
                if (execv(path, args) == -1) {
                    perror("execv");
                    exit(EXIT_FAILURE);
                }
            } else {
                wait(NULL);
            }

            free(path);
        } else {
            printf("%s: command not found\n", args[0]);
        }
    }

    free(input);
    return 0;
}

