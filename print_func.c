#include "main.h"
/**
 * _putchar - writes the character c to stdout
* @c: The character to print
*
* Return: On success 1.
* On error, -1 is returned, and errno is set appropriately.
*/

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _puts - a function that prints a string, followed by a new line, to stdout
 * @str: pionter varaible
 *
 * Return: (0) success
 */

void _puts(char *str)
{

	while (*str != '\0')
	{
		_putchar(*str);
		str++;
	}

}
