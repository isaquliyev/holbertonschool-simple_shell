#include "main.h"

char *_getline(void)
{
	char *line;
	size_t size = 0;
	int checker;

	checker = getline(&line, &size, stdin);
	if (checker == -1)
		free(line);
	else
		return (line);
	return (NULL);
}
