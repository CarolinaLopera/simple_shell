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
	char *line;
	size_t lineSize = 0;
	int count_line = 0;

	count_line = getline(&line, &lineSize, stdin);

	if (count_line == -1)
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

void ctrl_C(int signal)
{
	write(STDOUT_FILENO, "\n", 2);
	prompt();
	(void)signal;
}
