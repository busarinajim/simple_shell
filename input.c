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

/**
 * tokenize_input - Splits a string into tokens.
 * @input: The input string.
 *
 * Return: An array of tokens.
 */
char **tokenize_input(char *input)
{
	char **tokens = NULL;
	char *token;
	size_t i = 0;
	int bufsize = 64;

	tokens = malloc(sizeof(char *) * bufsize);
	if (!tokens)
		return (NULL);

	token = strtok(input, " \n");
	while (token)
	{
		tokens[i++] = token;
		token = strtok(NULL, " \n");
	}

	tokens[i] = NULL;
	return (tokens);
}
