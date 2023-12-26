#include "shell.h"



void non_interactive(char *filename)
{
	FILE *input_file = fopen(filename, "r");
    if (input_file == NULL)
    {
        perror("Error opening file");
        exit(1);
    }

    char *command = NULL;
    size_t len = 0;
    char **tokens;
    pid_t child_pid;

    while (getline(&command, &len, input_file) != -1)
    {
	    tokens = tokenize(command);

            if (strcmp(tokens[0], "exit") == 0)
            {
                exit(0);
            }
            else if (strcmp(tokens[0], "env") == 0)
            {
                for (char **env = environ; *env != NULL; env++)
                {
                    printf("%s\n", *env);
                }
            }
            else
            {
                char *path = find_in_path(tokens[0]);
                if (path)
                {
                    child_pid = fork();
                    if (child_pid == 0)
                    {
                       char *args[] = {path, NULL}; /* updated */
			execve(path, tokens, environ);
                        perror("execve");/*updated*/
			exit(EXIT_FAILURE); /*updated*/
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
    }
    free(command);
    free(tokens);

    fclose(input_file);
}
