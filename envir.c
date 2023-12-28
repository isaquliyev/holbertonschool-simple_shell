#include <stdio.h>
#include <string.h>
#include "main.h"

char **pathfinder(void)
{
	char **array;
	char *temp;
	int i;

	while (*environ)
	{
		array = malloc(2 * sizeof(char *));
		array = splitter(*environ, "=");
		if (!strcmp(*array, "PATH"))
		{
			temp = strdup(*(array + 1));
			for (i = 0; i < 2; i++)
			{
				free(*(array + i));
			}
			free(array);
			break;
		}
		for (i = 0; i < 2; i++)
		{
			free(*(array + i));
		}
		free(array);
		environ++;
	}
	array = splitter(temp, ":");
	i = 0;
	while (array[i])
	{
		array[i] = realloc(array[i], strlen(array[i]) + 2);
		strcat(array[i], "/");
		i++;
	}
	if (temp)
		free(temp);
	return (array);
}
