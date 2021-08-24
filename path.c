#include "header.h"
/**
 * split_path
 * @path: directories string
 * Return: array of strings
 */
char **split_path(char *path)
{
	char *str_sep;
	const char *delim = ":";
	int i, cont, j = 0;
	char **archive = NULL;

	for (i = 0, cont = 0; path[i]; i++)
	{
		if (path[i] == ':')
		{
			cont++;
		}
	}

	archive = malloc((cont + 2) * sizeof(char *));
	str_sep = strtok(path, delim);
	while (str_sep != NULL)
	{
		archive[j] = str_sep;
		j++;
		str_sep = strtok(NULL, delim);
	}
	archive[j] = NULL;
	return (archive);
}
/**
 * discover_path - recorre el path y encuentra
 * el directorio donde se va a ejecutar el comando
 * @line: input command
 * @env: environment
 * Return: la ruta
 */
char *discover_path(char *line, char **env)
{
	int i, j, len_path, len_env;
	char *path = "PATH=/usr/local/sbin:/usr/local/bin:/usr/sbin:/usr/bin:/sbin:/bin:/usr/games:/usr/local/games:/snap/bin";
	char *environ_path;
	char *dir;
	char **tokens;
	struct stat st;
	pid_t child;
	int exec;
	
	len_path = length(path);
	for (i = 0; env[i]; i++)
	{
		len_env = length(env[i]);
		if (len_path == len_env)
		{
			environ_path = env[i];
		}
	}
	tokens = malloc(50 * sizeof(char *));
	if (!tokens)
		return (NULL);
	dir = malloc(50 * sizeof(char));
	if (!dir)
		return (NULL);
	tokens = split_path(environ_path);
	for (j = 0; tokens[j]; j++)
	{
		dir = tokens[j];
		_strcat(dir, "/");
		_strcat(dir, line);
		tokens[0] = dir;
		if (stat(tokens[0], &st) == 0)
		{
			child = fork();
			wait(NULL);
			if (child == 0)
			{
				exec = execve(tokens[0], tokens, NULL);
				if (exec == -1)
					printf("command not found");
			}
		}
	}
	return (0);
}
