#include "main.h"

/**
 * b_exit - function that implement exit built in
 */
void b_exit(void)
{
	exit(0);
}

/**
 * b_env - function that implement env built-in
 */
void b_env(void)
{

	char **env;

	for (env = environ; *env != NULL; env++)
	{
		printf("%s\n", *env);
	}
}

