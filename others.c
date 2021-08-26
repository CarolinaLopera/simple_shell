#include "header.h"

/**
 * prompt - This function print a prompt.
 *
 * Return: void.
 */
void prompt(void)
{
	char *prompt = "JAC$ ";

	write(STDOUT_FILENO, prompt, 5);
}

/**
 * get_line - This function get the a string of stdin.
 *
 * Return: Always a string that is the line.
 */
char *get_line()
{
	char *line = NULL;
	size_t lineSize = 0;
	int count_line = 0;

	count_line = getline(&line, &lineSize, stdin);

	if (count_line == EOF)
	{
		free(line);
		line = NULL;
		write(STDIN_FILENO, "\n", 1);
		exit(0);
	}
	if (count_line > 1)
		return (line);
	free(line);
	line = NULL;
	return (NULL);
}

/**
 * ctrl_C - This function ignore the signal of interruption ctrl-c.
 *
 * Return: Always void.
 * @signal: Is the signal to ignore.
 */
void ctrl_C(int signal)
{
	(void)signal;

	write(STDOUT_FILENO, "\n", 1);
	prompt();
}
