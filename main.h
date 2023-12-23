#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>
int _getline(char **lineptr, size_t *n, FILE *stream);
char **splitter(char *str, char **array);
#endif
