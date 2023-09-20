#include "main.h"

/**
 * executor - a program that executes command from our custom shell
 * @av: array of command line arguments.
 *
 * Return: (nothing or -1 on error)
 */

int executor(char **av, char *argv[], int count, int *exit_status)
{
	char *pathname = strdup(pathfinder(av));
	pid_t shellpid;
	struct stat buff;
	int wstatus;
	/*int exitstatus;*/

	if (stat(pathname, &buff) != 0)
	{
		_perror(av, argv, count);
		free(pathname);
		exit(127);
		/*exit_status = 127;*/
		return (0);
	}

	shellpid = fork();
	if (shellpid < 0)
	{
		perror("forking process failed");
		exit(EXIT_FAILURE);
	}
	else if (shellpid == 0)
	{
		if (execve(pathname, av, environ) == -1)
		{
			perror("Execution error");
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&wstatus);
		if (WIFEXITED(wstatus))
		{
			*exit_status = WEXITSTATUS(wstatus);
		}	
	}
	free(pathname);
	return (0);
}
