#include <stdio.h>
#include <stdlib.h>
#include "main.h"

int main()
{
	char *my_prompt = NULL;
	size_t len = 0;
	printf("$ ");
	_getline(&my_prompt, &len, stdin);
	printf("%s\n", my_prompt);
	return (0);
}
