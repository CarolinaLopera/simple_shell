#include "header.h"

/**
 * principal function
 * return: 0
*/

int main()
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
				exe(words);
			}
			exit(0);
		}
		prompt();
		line = get_line();
		if (line != NULL)
		{
			words = token(line);
			exe(words);
		}
	}
	return (0);
}
