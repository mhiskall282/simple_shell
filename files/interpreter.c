#include "main.h"

/**
 * interpret - a function that checks whether a command is a
 * bulit-in command or executable or otherwise
 * @av: argument vector
 *
 * Return: (1)
 */

int interpret(char **av, char *argv[], int count, int *exit_status)
{
	int j;
	built_in ops[] = {
		{"exit", sh_exit},
		{"cd", sh_chdir},
		{"env", printenv},
		{"setenv", _setenv},
		{"unsetenv", _unsetenv},
		{NULL, NULL}
	};



	if (av[0] == NULL)
	{
		return (0);
	}
	for (j = 0; ops[j].str != NULL; j++)
	{
		if (strcmp(av[0], ops[j].str) == 0)
		{
			return (ops[j].fp(av, exit_status));
		}
	}
	executor(av, argv, count, exit_status);
	return (0);
}
