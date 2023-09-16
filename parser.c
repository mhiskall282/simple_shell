#include "main.h"

char **token();
/**
 * token - a program that prints "$ ", wait for the user to enter a command
 * prints it on the next line.
 *
 * Return: (number read)
 */

char **token()
{
	char *buffer = NULL, *buffer_cpy;
	size_t size = 0;
	char *delim = " \n";
	char *str;
	ssize_t nb_read;
	int i, ac = 0;
	char **av = NULL;

	nb_read = getline(&buffer, &size, stdin);
	if (nb_read == -1)
	{
		if (feof(stdin))
		{
			exit(0);
		}
		else
		{
			perror("Error reading file");
			free(buffer);
			exit(1);
		}
	}

	buffer_cpy = strdup(buffer);

	str = strtok(buffer, delim);
	while (str)
	{
		str = strtok(NULL, delim);
		ac++;
	}

	av = malloc(sizeof(*av) * (ac + 1));
	if (av == NULL)
	{
		perror("memory allocation failed");
		free(buffer);
		free(buffer_cpy);
		exit(1);
	}
	str = strtok(buffer_cpy, delim);

	for (i = 0; i < ac; i++)
	{
		av[i] = str;
		str = strtok(NULL, delim);
	}
	av[ac] = NULL;

	free(buffer);
	return (av);
}
