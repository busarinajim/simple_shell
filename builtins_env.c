#include "shell.h"

/**
 * handle_exit - Built-in exit command
 * @args: Array of arguments
 */
void handle_exit(char **args)
{
    (void)args;
    exit(EXIT_SUCCESS);
}

