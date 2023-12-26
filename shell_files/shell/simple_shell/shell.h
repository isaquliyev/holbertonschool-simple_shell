#ifndef _SHELL_H
#define _SHELL_H


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#define MAX_TOKENS 100

extern char **environ; 

/* Function prototypes */
char **tokenize(char *command);
char *find_in_path(char *command);
void handle_errors(const char *message);
void non_interactive(char *filename);


#endif
