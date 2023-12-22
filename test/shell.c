#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

char **splitter(char *str, char **array)
{
    const char delim[2] = " ";
    char *token;
    int i = 0;
    token = strtok(str, delim);
    while (token != NULL)
    {
        *(array + i) = token;
        i++;
        token = strtok(NULL, delim);
    }
    *(array + i) = NULL;
    return (array);
}

int main()
{
	char *my_prompt;
	char *last;
	char **array = malloc(1);
	*array = malloc(1);
	size_t len = 0;
	int i = 0;
	pid_t pid;
	char *shell[] = {"./shell", NULL};

	pid = fork();
	if (pid == 0)
	{
	printf("#cisfun$ ");
	getline(&my_prompt, &len, stdin);
	while (*(my_prompt + i) != '\0')
	{
		if (*(my_prompt + i) == '\n')
		{
			*(my_prompt + i) = '\0';
			break;
		}
		i++;
	}
	i = 0;
	array = splitter(my_prompt, array);
	while (*(array + i) != NULL)
	{
		printf("%s ", array[i]);
		i++;
	}
	execve(array[0], array, NULL);
	exit(99);
	}
	else {
		wait(NULL);
		/*
		if (*array == "\0")
			exit(100);
		execve(shell[0], shell, NULL);
		*/
	}	
	return (0);
}
