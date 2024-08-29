#include "shell.h"

/**
 * main - Entry point for the simple shell
 * Return: Always 0 (Success)
 */
int main(void)
{
    char *input = NULL;
    size_t len = 0;
    ssize_t read;

    while (1)
    {
        display_prompt();
        read = getline(&input, &len, stdin);

        if (read == -1)
        {
            free(input);
            break;
        }

        if (read > 1)
        {
            input[read - 1] = '\0';
            execute_command(input);
        }
    }

    return (0);
}

