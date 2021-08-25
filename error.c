#include "header.h"

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
	(void)num_c;

	write(STDOUT_FILENO, argv[0], length(argv[0]));
	write(STDOUT_FILENO, ": ", 2);
	/*write(STDOUT_FILENO, num_c, 1);*/
	printf("%i", num_c);
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, words, length(words));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "not found\n", 10);
}

void error_permisions(char *argv[], int num_c, char *words)
{
	(void)num_c;

	write(STDOUT_FILENO, argv[0], length(argv[0]));
	write(STDOUT_FILENO, ": ", 2);
	/*write(STDOUT_FILENO, num_c, 1);*/
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, words, length(words));
	write(STDOUT_FILENO, ": ", 2);
	write(STDOUT_FILENO, "permission denied\n", 18);
}
