#include "main.h"

/**
 * splitter - splits given string into parts
 *
 * @str: given string
 *
 * @array: double dimensional free char array
 *
 * Return: modified char array.
 */

char **splitter(char *str, char **array)
{
	const char delim[4] = " \n\t";
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
