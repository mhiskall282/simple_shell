#include "main.h"

/**
 *  * _prompt - shell prompt
 *   *
 *    * Return: (void)
 */

void _prompt(void)
{
		write(STDIN_FILENO, "$ ", 2);
}
