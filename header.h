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
int exe(char **words, int num_w, char *env[]);
int length(char *string);
int number_words(char *str);
void prompt(void);
char *get_line();
char **split_path(char *path);
void discover_path(char *line, char **env, int num_c);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

#endif
