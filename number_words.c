#include "header.h"
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
	int len = length(str) -1;
	int i, w = 0;

	for (i = 0; str[i]; i++)
	{
		if (str[i] == ' ' && str[i + 1] != ' ' && (i + 1 != len))
		{
			w++;
		}
	}

	if (str[0] != ' ')
	{
		w++;
	}
	return (w);
}
