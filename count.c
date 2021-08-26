#include "header.h"

/**
 * length - count number of characters
 * @string: is the string
 * Return: number of chars
 */
int length(char *string)
{
	int i = 0;

	while (string[i] != '\0')
		i++;

	return (i);
}

/**
 * number_words - count the words in a string
 * @str: string
 * @delim: is a delimitador for string
 * Return: number of words
 */
int number_words(char *str, char delim)
{
	int len = length(str) - 1;
	int i, w = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == delim && str[i + 1] != delim && (i + 1 != len))
			w++;
	}

	if (str[0] != delim)
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
	dest[a] = '\0';
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
/**
 * _strcmp - compare two strings
 * @s1: string one
 * @s2: string two
 * Return: 0 if success
 */
int _strcmp(char *s1, char *s2)
{
	int a;

	for (a = 0; s1[a] != '\0' && s2[a] != '\0'; a++)
	{
		if (s1[a] != s2[a])
		{
			return (s1[a] - s2[a]);
		}
	}
	return (0);
}
