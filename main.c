#include "main.h"

/**
 * main - entry point
 *
 * Return: (0)
 */

int main(int argc __attribute__((unused)), char *argv[])
{
	char **parsed = NULL;
	int status = 1, count = 0, exit_status = 0;

	while (status)
	{
		count++;
		if (isatty(STDIN_FILENO))
		{
			_prompt();
		}
		parsed = token();
		interpret(parsed, argv, count, &exit_status);
		/*free(parsed);*/
	}

	/*free(parsed);*/
	return (exit_status);
}

