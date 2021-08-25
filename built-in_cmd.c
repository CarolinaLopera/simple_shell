#include "header.h"

/**
 * environment - print the environment
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
 * Return: always 0
 */
int built_in_commands(char **words, char **env)
{
	if (_strcmp(words[0], "exit") == 0)
	{
		exit(0);
	}
	else if (_strcmp(words[0], "env") == 0)
	{
		environ_print(env);
	}
	
	return (0);
}
