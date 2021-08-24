#include "header.h"

/**
 * prompt - This function print a prompt.
 *
 * Return: void.
 */
void prompt(void)
{
	char *prompt = "JAC$ ";

	write(STDOUT_FILENO, prompt, 5);
}

/**
 * length - count number of characters
 * @string: is the string
 * Return: number of chars
 */
int length(char *string)
{
	int i = 0;

	while (string[i])
		i++;

	return (i);
}

/**
 * number_words - count the words in a string
 * @str: string
 * Return: number of words
 */
int number_words(char *str)
{
	int len = length(str) - 1;
	int i, w = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ' && str[i + 1] != ' ' && (i + 1 != len))
			w++;
	}

	if (str[0] != ' ')
		w++;
	return (w);
}

/**
 * _strcat - concatena dos strings
 *@dest:string destino
 *@src: string fuente
 *
 *Return: dest
 */
char *_strcat(char *dest, char *src)
{
	int a, b;

	for (a = 0; dest[a] != 0; a++)
		;

	for (b = 0; src[b]; b++)
	{
		dest[a] = src[b];
		a++;
	}
	dest[a] = 0;
	return (dest);
	
}

/**
 * _strcpy - copy a string
 * @dest: destino
 * @src: fuente
 * Return: dest cpy
 */
char *_strcpy(char *dest, char *src)
{
	int a, b;

	for (a = 0; *(src + a) != '\0'; a++)
		;
	for (b = 0 ; b < a ; b++)
		dest[b] = src[b];

	dest[a] = '\0';
	return (dest);
}
