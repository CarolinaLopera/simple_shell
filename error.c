#include "header.h"

void print_int(int num)
{
	int num_cpy = num;

	if (num < 10)
	{
		num += '0', write(1, &num, 1);
		return;
  	}

    num /= 10, num += '0';
    write(1, &num, 1);
    num_cpy %= 10, num_cpy += '0';
    write(1, &num_cpy, 1);
}

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 
int write_char(char c)
{
	return (write(1, &c, 1));
}

void print_int(int n)
{
	if (n / 10 != 0)
	{
		print_int(n / 10);
	}
  	write_char((n % 10) + '0');
}*/

/**
 * error_found - print a menssage about command not fount in stdout.
 *
 * Return: Always void.
 * @argv: is the name the program.
 * @num_c: is the total number of commands executed.
 * @words: is the name of the command not found.
 */
void error_found(char *argv[], int num_c, char *words)
{
	write(STDOUT_FILENO, argv[0], length(argv[0]));
	write(STDOUT_FILENO, ": ", 2);
	print_int(num_c);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, words, length(words));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}

void error_permisions(char *argv[], int num_c, char *words)
{
	write(STDOUT_FILENO, argv[0], length(argv[0]));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, &num_c, sizeof(num_c));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, words, length(words));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "permission denied\n", 18);
}
