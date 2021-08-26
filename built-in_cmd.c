#include "header.h"
/**
 * environ_print - print the environment
 * @env: evironment
 * Return: nothing
 */
void environ_print(char **env)
{
	while (*env)
	{
		write(STDOUT_FILENO, *env, length(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
/**
 * built_in_commands - identify if the input is bultin
 * @words: input tokenized
 * @env: environment
 * @line: is the line get whith get_line
 * Return: always 0
 */
int built_in_commands(char **words, char **env, char *line)
{
	if (_strcmp(words[0], "exit") == 0)
	{
		free(words), words = NULL;
		free(line), line = NULL;
		exit(0);
	}
	else if (_strcmp(words[0], "env") == 0)
	{
		free(words), words = NULL;
		environ_print(env);
		return (0);
	}

	return (1);
}
