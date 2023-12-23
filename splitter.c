#include "main.h"
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
    *(array + i) = NULL;
    return (array);
}
