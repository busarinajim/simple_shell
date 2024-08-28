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
