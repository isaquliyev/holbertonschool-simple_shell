#include "main.h"

/**
 * splitter - splits given string into parts
 *
 * @str: given string
 *
 * Return: modified char array.
 */

char **splitter(char *str)
{
	const char delim[4] = " \n\t";
	char *token;
	char **array = malloc(strlen(str) * sizeof(char *));
	int i = 0;

	token = strtok(str, delim);
	while (token != NULL)
	{
		*(array + i) = strdup(token);
		if (!*(array + i))
		{
			free(*(array + i));
			exit(99);
		}
		i++;
		token = strtok(NULL, delim);
	}
	*(array + i) = NULL;
	return (array);
}
