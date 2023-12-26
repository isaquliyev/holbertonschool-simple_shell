#include <stdio.h>
#include <string.h>

extern char **environ;

void print_dir()
{
	char *path = _getenv("PATH");
	char *token = strtok(path, ":");
	while (token != NULL)
	{printf("%s\n", token);
		token = strtok(NULL, ":");
	}
}

