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
	int i = 0, w = 0;
	int len = length(str) -1;

	if(str[i] == ' ' || str[i] == '\t')
	{
		for (; str[i] == ' ' && str[i] != 0; i++)
		{
			w = 0;
		}
	}
	for (;str[i]; i++)
	{
		if (str[i] == ' ' && str[i + 1] != ' ' && (i + 1 != len))
		{
			w++;
		}
	}
	if (str[0] != 0)
	{
		w++;
	}
	printf("%i", w);
	return (w);
}
