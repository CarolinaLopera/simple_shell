#include "header.h"

/**
 * write_char - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int write_char(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_int - Function to print numbers int in console.
 *
 * Return: Always void.
 * @n: is an integer that takes to print.
 */
void print_int(int n)
{
	if (n / 10 != 0)
	{
		print_int(n / 10);
	}
	write_char((n % 10) + '0');
}

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

/**
 * error_permisions - print a menssage about permissions denied.
 *
 * Return: Always void.
 * @argv: is the name the program.
 * @num_c: is the total number of commands executed.
 * @words: is the name of the command not found.
 */
void error_permisions(char *argv[], int num_c, char *words)
{

	write(STDOUT_FILENO, argv[0], length(argv[0]));
	write(STDOUT_FILENO, ": ", 2);
	print_int(num_c);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, words, length(words));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "permission denied\n", 18);
}
