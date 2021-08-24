#include "header.h"

/**
 * main - main function
 * return: 0
*/

int main(int argc, char *argv[], char *env[])
{
	char **words = NULL, *line;
	
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
			discover_path(line, env);
			/*if (words != NULL)
			{
				exe(words, line);
				free(words);
				words = NULL;
				free(line);
				line = NULL;	
				}*/
		}
	}
	/*(void)env;*/
	(void)argc;
	(void)argv;
	return (0);
}
