#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

/**
 * main - Simple shell command interpreter
 *
 * Return: Always 0.
 */
int main(void)
{
    char *command = NULL;
    size_t len = 0;
    char *token;
    pid_t child_pid;
    char *av[2];
	
    if (isatty(STDIN_FILENO))
    {
    while (1)
    {
        printf("#cisfun$ ");
        if (getline(&command, &len, stdin) == -1)
        {
            perror("error");
            exit(EXIT_FAILURE);
        }
    }
    else 
    {
	    FILE *fd = fopen(argv[1], "r");
	    if (fd == NULL)
	    {
		    perror("Error opening file");
		    exit(1);
	    }
	    while (getline(&command, &len, fd) != -1) 


        command[strcspn(command, "\n")] = '\0';

        token = strtok(command, " ");
        if (token == NULL)
        {
            continue;
        }

        child_pid = fork();

        if (child_pid == -1)
        {
            perror("Error in fork");
            free(command);
            exit(99);
        }
        else if (child_pid == 0)
        {
            av[0] = token;
            av[1] = NULL;
            execve(token, av, NULL);
            perror("Error in execve");
            free(command);
            exit(100);
        }
        else
        {
            wait(NULL);
        }
    }

    free(command);
    return 0;
}
