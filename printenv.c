#include "main.h"

/**
 * printenv - print environment variable
 * @av: argumnet vector
 *
 * Return: (zero)
 */

int printenv(__attribute((unused)) char **av, __attribute((unused)) int *exit_status)
{
	int i = 0;

	for (; environ[i] != NULL; i++)
	{
		puts(environ[i]);
	}
	return (0);
}

/**
 * _setenv - a function that adds or modifies environment variables
 * @av: command arguments
 *
 * Return: (0) on success
 */

int _setenv(char **av, __attribute((unused)) int *exit_status)
{
	int status = 0;

	if (av[1] != NULL && av[2] != NULL)
	{
		status = setenv(av[1], av[2], 1);
		if (status == -1)
		{
			perror("setenv failed");
			exit(1);
		}
	}
	else
	{
		perror("setenv usage error");
		exit(1);
	}
	return (0);
}

/**
 *  * _unsetenv - a function that adds or modifies environment variables
 *   * @av: command arguments
 *    *
 *     * Return: (0) on success
 *      */

int _unsetenv(char **av, __attribute((unused)) int *exit_status)
{
	int status = 0;

	if (av[1] != NULL && av[2] == NULL)
	{
		status = unsetenv(av[1]);
		if (status == -1)
		{
			perror("unsetenv failed");
			exit(1);
		}
	}
	else
	{
		perror("setenv usage error");
		exit(1);
	}
	return (0);
}
