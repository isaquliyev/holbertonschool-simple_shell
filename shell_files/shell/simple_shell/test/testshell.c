#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_ARGS 20

int main(void) {
    char *input = NULL;
    size_t len = 0;
    ssize_t read;
    pid_t child_pid;
    char *args[MAX_ARGS], *token;
    int argc;

    while (1) {
        argc = 0;
        printf("$ ");
        fflush(stdout);

        read = getline(&input, &len, stdin);
        if (read == -1) {
            perror("getline");
            exit(EXIT_FAILURE);
        }

        input[strcspn(input, "\n")] = '\0';

        token = strtok(input, " ");
        while (token != NULL && argc < MAX_ARGS - 1) {
            args[argc++] = token;
            token = strtok(NULL, " ");
        }
        args[argc] = NULL;

        child_pid = fork();
        if (child_pid == -1) {
            perror("fork");
            exit(EXIT_FAILURE);
        }

        if (child_pid == 0) {
            if (execvp(args[0], args) == -1) {
                perror("execvp");
                exit(EXIT_FAILURE);
            }
        } else {
            wait(NULL);
        }
    }

    free(input);
    return 0;
}

