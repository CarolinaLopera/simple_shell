#include "header.h"

/**
 * split_path
 * @path: directories string
 * Return: array of strings
 */
char **split_path()
{
	char *tok, **num_dir = NULL, *path_cpy;
	const char *delim = ":";
	char *path = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
	int count, j = 0;

	path_cpy = malloc(length(path) * sizeof(char));
	path_cpy = _strcpy(path_cpy, path);
	count = number_words(path, ':');

	num_dir = malloc((count + 2) * sizeof(char *));
	tok = strtok(path_cpy, delim);
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
	char *tok, **words = NULL;
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
