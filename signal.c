#include "shell.h"

/**
 * sig_handler - Prints a new prompt upon receiving `SIGINT`.
 * @sig: The signal number.
 */

void sig_handler(int sig)
{
	(void)sig;
	write(STDOUT_FILENO, "\n$ ", 3);
}
