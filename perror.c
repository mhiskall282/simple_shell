#include "main.h"
/**
 * _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/

int _puterror(char c)
{
	return (write(2, &c, 1));
}

/**
 * _puts - a function that prints a string, followed by a new line, to stdout
 * @str: pionter varaible
 *
 * Return: (0) success
 */

void _puts_error(char *str)
{

	while (*str != '\0')
	{
		_puterror(*str);
		str++;
	}

}

/**
 * _perror - print a error to stderr
 * @av: shell command
 * @argv: argument vector
 * @count: shell loop count
 *
 * Return: (1) on success
 */

void _perror(char **av, char *argv[], int count)
{
	char *count_str;

	count_str = _itoa(count);

	_puts_error(argv[0]);
	_puts_error(": ");
	_puts_error(count_str);
	_puts_error(": ");
	_puts_error(av[0]);
	_puts_error(": ");
	_puts_error("not found\n");

	free(count_str);
}
