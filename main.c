#include "header.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 * @env: Is the environment.
 * @argv: Is each argumnet passed to the program.
 * @argc: Is the number the arguments passed to the program.
 */
int main(int argc, char *argv[], char *env[])
{
	char **words = NULL, *line = NULL;
	int num_words, num_commands = 0;
	(void)argc, (void)argv;

	while (1)
	{
		signal(SIGINT, ctrl_C);
		if (!isatty(STDIN_FILENO))
		{
			line = get_line();
			if (line != NULL)
			{
				num_words = number_words(line, ' ');
				words = token(line);
				if (words != NULL)
					exe(words, num_words, env, argv, num_commands);
			}
			exit(0);
		}
		prompt();
		line = get_line();
		if (line != NULL)
		{
			num_words = number_words(line, ' ');
			words = token(line);
			built_in_commands(words, env);
			if (words != NULL)
			{
				num_commands = exe(words, num_words, env, argv, num_commands);
				free(line);
				line = NULL;
			}
		}
	}
	return (0);
}
