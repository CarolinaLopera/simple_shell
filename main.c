#include "header.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 *
 */
int main(int argc, char *argv[], char *env[])
{
	char **words = NULL, *line = NULL;
	int num_words;
	(void)argc, (void)argv;

	while (1)
	{
		if (!isatty(STDIN_FILENO))
		{
			line = get_line();
			if (line != NULL)
			{
				words = token(line);
				if (words != NULL)
					exe(words, num_words, env);
			}
			exit(0);
		}
		prompt();
		line = get_line();
		if (line != NULL)
		{
			num_words = number_words(line);
			words = token(line);
			if (words != NULL)
				exe(words, num_words, env);
		}
	}
	return (0);
}
