#include "header.h"

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */

int main(void)
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
