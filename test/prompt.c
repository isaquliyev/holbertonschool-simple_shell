#include <stdio.h>
#include <stdlib.h>

int main()
{
	char *my_prompt = NULL;
	size_t len = 0;
	printf("$ ");
	getline(&my_prompt, &len, stdin);
	printf("%s", my_prompt);
	return (0);
}
