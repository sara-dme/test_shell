#ifndef MAIN_H
#define MAIN_H
extern char **environ;
void find_path(char **environ);
int _strlen(const char *s);
char *_strcpy(char *dest, char *src);
void exec_cmd(char **args);
void launch_prog(char **args);
void cmds(char *args[], char **envp);
int _strcmp(char *s1, char *s2);
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <unistd.h>

#endif
