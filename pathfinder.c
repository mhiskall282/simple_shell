#include "main.h"

/**
 * pathfinder - a program that generate and returns the full path of a command
 * @av: input command
 *
 * Return: (command path)
 */

char *pathfinder(char **av)
{
	char *token = NULL;
	struct stat buf;
	char *cur_path = strdup(getenv("PATH"));
	char *full_path = NULL;


	if (!av[0])
	{
		free(cur_path);
		return (NULL);
	}
	token = strtok(cur_path, ":");
	while (token)
	{
		full_path = malloc(strlen(av[0]) + strlen(token) + 2);
		if (full_path == NULL)
		{
			perror("fullpath malloc error");
			free(cur_path);
			exit(1);
		}

		full_path[0] = '\0';
		
		strcpy(full_path, token);
		strcat(full_path, "/");
		strcat(full_path, av[0]);

		full_path[strlen(token) + strlen(av[0]) + 1] = '\0';

		if (stat(full_path, &buf) == 0)
		{
			free(cur_path);
			return (full_path);
		}
		free(full_path);
		token = strtok(NULL, ":");
	}
	free(cur_path);

	return (stat(av[0], &buf) == 0 ? av[0] : av[0]);


	return (NULL);
}
