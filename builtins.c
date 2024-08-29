#include "shell.h"

/**
 * handle_exit - Exits the shell.
 */

void handle_exit(void)
{
	exit(0);
}

/**
 * print_env - Prints the current environment variables.
 */
void print_env(void)
{
	char **env = environ;

	while (*env)
	{
		write(STDOUT_FILENO, *env, strlen(*env));
		write(STDOUT_FILENO, "\n", 1);
		env++;
	}
}
