#ifndef MAIN_H
#define MAIN_H
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
void exec_cmd(char **args);
void launch_prog(char **args);
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

#endif
