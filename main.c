#include "shell.h"

/**
 * main - Runs a simple UNIX command interpreter (shell)
 * @argc: Number of arguments provided to program
 * @argv: Array of pointers to arguments
 *
 * Return: The exit status of the last command.
 */
int main(int argc, char *argv[])
{
        char *input, **args;
        int status = 0;

        (void)argc;
        (void)argv;

        signal(SIGINT, sig_handler);
	
	while (1)
        {
                write(STDOUT_FILENO, "$ ", 2);
                input = read_input();
                if (!input)
                        break;

                args = tokenize_input(input);
                if (args[0] == NULL)
                {
                        free(input);
                        free(args);
                        continue;
                }

                if (strcmp(args[0], "exit") == 0)
                        handle_exit();
                else if (strcmp(args[0], "env") == 0)
                        print_env();
                else
                        status = execute(args);

                free(input);
                free(args);
        }

        return (status);
}
