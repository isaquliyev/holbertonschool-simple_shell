#include "main.h"

void array_cleaner(char **array)
{
	int i = 0;

	while (array[i])
	{
		free(array[i]);
		i++;
	}	
	free(array);
}
