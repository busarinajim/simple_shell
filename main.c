#include "shell.h"

/**
 * main - Runs a simple UNIX command interpreter (shell)
 *
 * Return: The exit status of the last command.
 */
int main(int argc, char *argv[])
{
	signal(SIGINT, sig_handler);

	while (1)
        {
                write(STDOUT_FILENO, "$ ", 2);
                input = read_input();
                if (!input)
                        break;
	}

	return (status);
}

void sig_handler(int sig);                                                                                                                                                                                                                                                                      /**                                                                                                                                              * sig_handler - Prints a new prompt upon receiving `SIGINT`.                                                                                    * @sig: The signal number.                                                                                                                      */                                                                                                                                             void sig_handler(int sig)                                                                                                                       {
        (void)sig;                                                                                                                                      write(STDOUT_FILENO, "\n$ ", 3);
}
