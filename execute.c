#include "header.h"

/**
 * exe - This function execute a line of commands.
 *
 * Return: A int that is the new number the commands executed.
 * @words: Is a array of arguments passed to a program.
 * @num_w: Is the number of words of the attay.
 * @env: Is the environment.
 * @argv: Is each argumnet passed to the program.
 * @num_c: Is a number to add a command executed.
 */
int exe(char **words, int num_w, char *env[], char *argv[], int num_c)
{
	int exec = 0, i, len;
	char *argx = NULL;
	pid_t p1, p2;

	num_w--, num_c++;
	len = length(words[num_w]) - 1;
	argx = malloc((len + 1) * sizeof(char));

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
 * @words: Is a array of arguments passed to a program.
 * @env: Is the environment.
 * @argv: Is each argumnet passed to the program.
 * @num_c: Is a number to add a command executed.
 */
void discover_path(char **words, char **env, char *argv[], int num_c)
{
	int i, acce, len, len2, len3;
	char *dir_current = NULL, **num_dir = NULL, *path;
	pid_t child;
	char *path_1 = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr";
	char *path_2 = "/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
	(void)env;
	len = length(path_1);
	len3 = length(path_2);

	path = malloc((len + len3 + 2) * sizeof(char));
	path = _strcpy(path, path_1);
	path = _strcat(path, path_2);
	num_dir = split_path(path);
	for (i = 0; num_dir[i] != NULL; i++)
	{
		len2 = length(num_dir[i]);
		dir_current = malloc((len2 + 30) * sizeof(char));
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
					execve(dir_current, words, NULL); }
			else
				error_permisions(argv, num_c, words[0]);
			break; }
		free(dir_current), dir_current = NULL;
	}
	if (acce == -1)
		error_found(argv, num_c, words[0]);
	free(num_dir), num_dir = NULL;
	free(dir_current), dir_current = NULL;
	free(path), path = NULL;
}
