#include "header.h"

/**
 * get_line - This function get the a string of stdin.
 *
 * Return: Always a string that is the line.
 */
char *get_line()
{
	char *line;
	size_t lineSize = 0;
	int count_line = 0;

	count_line = getline(&line, &lineSize, stdin);

	if (count_line == EOF)
	{
		free(line);
		line = NULL;
		write(STDIN_FILENO, "\n", 1);
		exit(0);
	}
	if (count_line > 1)
		return (line);
	free(line);
	line = NULL;
	return (NULL);
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
	int j = 0, num_w = number_words(line);

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

	/*free(line);
	line = NULL;*/
	return (words);
}

/**
 * exe - This function execute a line of commands.
 *
 * Return: Always void.
 * @words: Is a array of arguments passed to a program.
 * @num_w: Is the number of words of the attay.
 * @num_c: Is a number to add a command executed.
 */
int exe(char **words, int num_w, char *env[])
{
	int exec = 0, i, num_commands = 0;
	int len;
	char *argx;
	pid_t p1;
	(void)env, (void)num_commands;

	num_w--;
	len = length(words[num_w]);
	len--;
	argx = malloc(len * sizeof(char));

	for (i = 0; i < len; i++)
	{
		argx[i] = *words[num_w];
		words[num_w]++;
	}
	argx[len] = '\0';
	words[num_w] = argx;

	/*for (i = 0; words[i] != NULL; i++)
		printf("%s\n", words[i]);*/

	p1 = fork();
	wait(NULL);
	if (p1 == 0)
	{
		exec = execve(words[0], words, NULL);
		if (exec == -1)
			write(STDOUT_FILENO, "./hsh: No such file or directory\n", 33);
	}
	free(argx);
	argx = NULL;
	free(words);
	words = NULL;
	return (0);
	/*discover_path(line, env, num_commands);*/

	/*free(line);
	line = NULL;*/
}
