#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_WORDS 1000
#define MAX_WORD_LENGTH 50

void split(const char *str)
{
	char *token; 
	char temp[strlen(str) + 1];
	strcpy(temp, str);
	token = strtok(temp, " ");

	while (token != NULL)
	{
		printf("%s\n", token);
		token = strtok(NULL, " ");
	}
}

int main(void)
{
	const char *str = "Hello holberton students";
	split(str);
	return (0);
}

	


