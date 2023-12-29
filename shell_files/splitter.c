#include "main.h"

/**
 * splitter - splits given string into parts
 *
 * @str: given string
 *
 * Return: modified char array.
 */

char **splitter(char *str, char *delim)
{
	char *token;
	char **array = malloc(strlen(str) * sizeof(char *));
	int i = 0, j;

	token = strtok(str, delim);
	while (token != NULL)
	{
		*(array + i) = strdup(token);
		if (!*(array + i))
		{
			exit(99);
		}
		i++;
		token = strtok(NULL, delim);
	}
	for (j = 0; j < i; j++)
	{
		free(array[j]);
	}
	*(array + i) = NULL;
	free(array);
	return (array);
}
