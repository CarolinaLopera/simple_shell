#include "header.h"

/**
 * principal function
 * return:0
*/

int main()
{
	char **words = NULL, *line;
	
	while (1)
	{
		line = prompt();
		if (line != NULL)
		{
			words = token(line);
			exe(words);
		}
	}
	return (0);
}
