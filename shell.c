#include "header.h"


char *prompt()
{
	char *prompt = "$ ", *line;
	size_t lineSize = 0;
	int count_line = 0;
	
	write(STDOUT_FILENO, prompt, 2);
	count_line = getline(&line, &lineSize, stdin);
	
	if (count_line > 1)
		return (line);
	free(line);
	line = NULL;
	return (NULL);
}
