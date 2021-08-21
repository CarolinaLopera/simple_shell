#include "header.h"

void prompt()
{
	char *prompt = "JAC$ ";

	write(STDOUT_FILENO, prompt, 5);
}

char *get_line()
{
	char *line;
	size_t lineSize = 0;
	int count_line = 0;

	count_line = getline(&line, &lineSize, stdin);

	if (count_line == -1)
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

char **token(char *line)
{
	const char *DELIM = " ";
	char *tok;
	char **words = NULL;
	int j = 0;
	int num_w = number_words(line);

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

void exe(char **words, char *line)
{
	int exec = 0;
	int num_w = number_words(line);
	int len = length(words[num_w - 1]) - 1, i = 0;
	char *argx = malloc((len) * sizeof(char));
	pid_t p1;

	for (; i < len; i++)
	{
		argx[i] = *words[num_w - 1];
		words[num_w - 1]++;
	}
	words[num_w - 1] = argx;

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
}
