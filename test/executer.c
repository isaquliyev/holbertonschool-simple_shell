#include "main.h"

void executer(char *command, char **array)
{
	char **path = pathfinder();
	char *temp;
	int i = 0;
	printf("SALAM");
	while (path[i])
	{
		execve(array[0], array, NULL);
		printf("SALAM\n");
		temp = strdup(strcat(path[i], command));
		free(array[0]);
		array[0] = strdup(temp);
		free(temp);
		i++;
	}
	return;
}
