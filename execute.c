#include "header.h"

/**
 * exe - This function execute a line of commands.
 *
 * Return: Always void.
 * @words: Is a array of arguments passed to a program.
 * @num_w: Is the number of words of the attay.
 * @num_c: Is a number to add a command executed.
 */
int exe(char **words, int num_w, char *env[], char *argv[], int num_c)
{
	int exec = 0, i, len;
	char *argx;
	pid_t p1, p2;

	num_w--, num_c++;
	len = length(words[num_w]) - 1;
	argx = malloc(len * sizeof(char));

	for (i = 0; i < len; i++)
	{
		argx[i] = *words[num_w];
		words[num_w]++;
	}
	argx[len] = '\0';
	words[num_w] = argx;

	p1 = fork();
	wait(NULL);
	if (p1 == 0)
		exec = execve(words[0], words, NULL);
	if (exec == -1)
	{
		p2 = fork();
		wait(NULL);
		if (p2 == 0)
			discover_path(words, env, argv, num_c);
	}
	free(argx), argx = NULL;
	free(words), words = NULL;
	return (num_c);
}

/**
 * discover_path - recorre el path y comprueda la existencia de una comando.
 * @line: input command
 * @env: environment
 * Return: la ruta
 */
void discover_path(char **words, char **env, char *argv[], int num_c)
{
	int i, acce;
	char *dir_current, **num_dir = NULL;
	pid_t child;
	(void)env;
	num_dir = split_path();

	for (i = 0; num_dir[i] != NULL; i++)
	{
		dir_current = malloc(length(num_dir[i]) * sizeof(char));
		dir_current = _strcpy(dir_current, num_dir[i]);
		_strcat(dir_current, "/"), _strcat(dir_current, words[0]);

		acce = access(dir_current, F_OK);
		if (acce == 0)
		{
			if (access(dir_current, X_OK) == 0)
			{
				child = fork();
				wait(NULL);
				if (child == 0)
					execve(dir_current, words, NULL);
			}
			else
				error_permisions(argv, num_c, words[0]);
			break;
		}
		free(dir_current), dir_current = NULL;
	}
	if (acce == -1)
		error_found(argv, num_c, words[0]);

	free(num_dir), num_dir = NULL;
	free(dir_current), dir_current = NULL;
}
