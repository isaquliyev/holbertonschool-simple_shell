#ifndef MAIN_H
#define MAIN_H
#include <stddef.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/types.h>

/* globar variable */
extern char **environ;

/* function prototypes */
char **splitter(char *str, char *delim);
char *_getline(void);
char **pathfinder(void);
void executer(char *command, char **array);
void environ_printer(void);
void array_cleaner(char **array);

#endif
