#include "header.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */

int main(void)
{
	char **words = NULL, *line = NULL;

	while (1)
	{
		if (!isatty(STDIN_FILENO))
		{
			line = get_line();
			if (line != NULL)
			{
				words = token(line);
				exe(words, line);
			}
			exit(0);
		}
		prompt();
		line = get_line();
		if (line != NULL)
		{
			words = token(line);
			if (words != NULL)
			{
				exe(words, line);
				free(words);
				words = NULL;
				free(line);
				line = NULL;
			}
		}
	}
	return (0);
}
