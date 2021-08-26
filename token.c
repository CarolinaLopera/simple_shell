#include "header.h"

/**
 * split_path - This function split the path.
 * Return: array of strings
 * @path: is the path of env.
 */
char **split_path(char *path)
{
	char *tok = NULL, **num_dir = NULL;
	const char *delim = ":";
	int count, j = 0;

	count = number_words(path, ':');

	num_dir = malloc((count + 2) * sizeof(char *));
	tok = strtok(path, delim);
	while (tok != NULL)
	{
		num_dir[j] = tok;
		j++;
		tok = strtok(NULL, delim);
	}
	num_dir[j] = NULL;

	return (num_dir);
}

/**
 * token - This split a string in words.
 *
 * Return: Always a array of pointers.
 * @line: Is the line take of stdin.
 */
char **token(char *line)
{
	const char *DELIM = " ";
	char *tok = NULL, **words = NULL;
	int j = 0, num_w = number_words(line, ' ');

	if (num_w == 0)
	{
		free(line);
		line = NULL;
		return (NULL);
	}

	words = malloc((num_w + 2) * sizeof(char *));
	tok = strtok(line, DELIM);
	while (tok != NULL)
	{
		words[j] = tok;
		j++;
		tok = strtok(NULL, DELIM);
	}
	words[j] = NULL;

	return (words);
}
