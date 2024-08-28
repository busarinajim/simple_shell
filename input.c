#include "shell.h"

/**
 * read_input - Reads a line of input from stdin.
 *
 * Return: The input string.
 */
char *read_input(void)
{
	char *input = NULL;
	size_t len = 0;
	ssize_t nread;

	nread = getline(&input, &len, stdin);
	if (nread == -1)
	{
		free(input);
		return (NULL);
	}

	return (input);
}
