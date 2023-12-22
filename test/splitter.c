#include <stdio.h>

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
char **splitter(char *str, char **array)
{
    const char delim[2] = " ";
    char *token;
    int i = 0;
    token = strtok(str, delim);
    while (token != NULL)
    {
        *(array + i) = token;
        i++;
        token = strtok(NULL, delim);
    }
    return (array);
}
int main()
{
    char str[] = "Hello and welcome to holberton school!";
    char **arr;
    arr = malloc(1);
    *arr = malloc(1);
    arr = splitter(str, arr);
    while (*arr)
    {
        printf("%s\n", *arr);
        arr++;
    }
    return (0);
}
