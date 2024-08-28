#include "shell.h"

/**
 * find_path - Finds the path of a command.
 * @command: The command to find.
 *
 * Return: The full path of the command or NULL if not found.
 */
char *find_path(char *command)
{
	char *path, *path_dup, *dir;
	struct stat st;
	char full_path[1024];

	if (stat(command, &st) == 0)
		return (strdup(command));

	path = getenv("PATH");
	if (!path)
		return (NULL);

	path_dup = strdup(path);
	dir = strtok(path_dup, ":");
	while (dir)
	{
		snprintf(full_path, sizeof(full_path), "%s/%s", dir, command);
		if (stat(full_path, &st) == 0)
		{
			free(path_dup);
			return (strdup(full_path));
		}
		dir = strtok(NULL, ":");
	}

	free(path_dup);
	return (NULL);
}

/**
 * execute - Executes a command in a child process
 * @args: An array of arguments.
 *
 * Return: 0 on success, or an error code.
 */
int execute(char **args)
{
	pid_t child_pid;
	char *command;
	int status;

	command = find_path(args[0]);
	if (!command)
	{
		perror(args[0]);
		return (127);
	}

	child_pid = fork();
	if (child_pid == -1)
	{
		perror("Error");
		free(command);
		return (1);
	}
	if (child_pid == 0)
	{
		if (execve(command, args, environ) == -1)
		{
			perror(args[0]);
			free(command);
			exit(1);
		}
	}
	else
	{
		wait(&status);
	}

	free(command);
	return (WEXITSTATUS(status));
}
