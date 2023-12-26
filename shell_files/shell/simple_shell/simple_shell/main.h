#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>
#include <sys/stat.h>


char *get_file_path(char *file_name);
char *get_file_loc(char *path, char *file_name);
int startWithForwardSlash(const char *str);
#endif