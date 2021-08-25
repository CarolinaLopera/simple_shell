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

int exe(char **words, int num_w, char *env[], char *argv[], int num_c);
void discover_path(char **words, char **env, char *argv[], int num_c);
char **token(char *line);
char **split_path();
char *get_line();
void prompt(void);

int length(char *string);
int number_words(char *str, char delim);
char *_strcat(char *dest, char *src);
char *_strcpy(char *dest, char *src);

void error_found(char *argv[], int num_c, char *words);
void error_permisions(char *argv[], int num_c, char *words);

#endif
