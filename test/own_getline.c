#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <stdlib.h>
#include <string.h>
#define BUFFER_SIZE 1024

int _getline(char **buf, int *len, FILE *file)
{
	int r = BUFFER_SIZE;
	FILE *fd;
	char *buffer = malloc(BUFFER_SIZE);
	fd = fopen(file, O_RDONLY);

	while (r == BUFFER_SIZE)
	{
		r = read(fd, buf, BUFFER_SIZE);
		*len += r;
	}
	printf("%d", *len);
	return (0);
}
int main()
{
	char *prompt;
	int len = 0;
	_getline(&prompt, &len, stdin);
}
