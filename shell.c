#include "main.h"
/*
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
*/
int main()
{
	char *my_prompt;
	char **array = malloc(1);
	int status;
	size_t len = 0;
	int i = 0;
	int num1;
	pid_t pid = getpid();
	char *shell[] = {"./shell", NULL};

	*array = malloc(1);
	
        //num1 = getline(&my_prompt, &len, stdin);
        //if (num1 == -1)
        //        exit(31);
	pid = fork();
	if (pid == 0)
	{
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
	execve(array[0], array, NULL);
	if (array[0] == NULL)
		exit(99);
	else
		printf("./shell: No such file or directory\n");

	exit(100);
	}
	else {
		printf("#cisfun$ ");
		num1 = getline(&my_prompt, &len, stdin);
		if (num1 == -1)
			exit(31);
		wait(&status);
		//printf("\n-------\n%s-------\n", my_prompt);
		execve(shell[0], shell, NULL);
		exit(99);
		
	}	
	return (0);
}
