#include "main.h"
/**
 *
 *
 */
void b_exit()
{
	exit(0);
}

/**
 *
 *
 */
void b_env()
{
	extern char **environ;
	char **env;
	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}

