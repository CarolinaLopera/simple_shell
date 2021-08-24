#ifndef _HOLBERTON_
#define _HOLBERTON_

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include <sys/wait.h>
#include <sys/types.h>
#include <sys/stat.h>

char **token(char *line);
void exe(char **words, char *line);
int length(char *string);
int number_words(char *str);
void prompt();
char *get_line();
char **split_path(char *path);
char *discover_path(char *line, char **env);
char *_strcat(char *dest, char *src);

#endif
