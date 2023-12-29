#include <stdio.h>
#include <string.h>
#include "main.h"

char **pathfinder(void)
{
	char **array;
	char *temp;
	int i, j = 0;

	while (environ[j])
	{
		array = splitter(environ[j], "=");
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
		j++;
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
