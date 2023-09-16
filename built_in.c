#include "main.h"

/**
 * sh_exit - a function that exit the shell
 * @av: arguments
 *
 * Return: (0)
 */

int sh_exit(char **av, int *exit_status)
{
	int i = 0;

	if (av[1] != NULL)
	{
		/*if (_isalpha(av[1][i]) == 1)
		{
			*exit_status = 2;
			exit(*exit_status);
		}*/
		*exit_status = atoi(av[1]);
		exit(*exit_status);
	}
	else
	{
		exit(*exit_status);
	}
	return (0);
}

/**
 * sh_chdir - a function that changes dir of a shell
 * @av: arguments
 *
 * Return: (1)
 */

int sh_chdir(char **av, __attribute((unused)) int *exit_status)
{
	if (av[1] == NULL)
	{
		fprintf(stderr, "Expects an argument after \"cd\"\n");
	}
	else if (chdir(av[1]) != 0)
	{
		perror("cd");
	}
	return (0);

}
