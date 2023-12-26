#include <stdio.h>
#include <string.h>
extern char **environ;
char *_getenv(const char *name)
{
	int i = 0;
	while (environ[i] != NULL)
	{
		if (strstr(environ[i], name) == environ[i])
		{
			return (environ[i] + strlen(name) + 1);
		}
		i++;
	}
	return (NULL);
}

