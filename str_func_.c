#include "main.h"

/**
 * _itoa - Function to Convert Integer To string
 * @x: Input integer
 * Return: Char Pointer
 */
char *_itoa(int x)
{
	int len = 0, i = 0, temp = x;
	char *str;

	if (x == 0)
	{
		str = malloc(2);
		if (str == NULL)
			return NULL;
		str[0] = '0';
		str[1] = '\0';
		return str;
	}

	while (temp != 0)
	{
		len++;
		temp /= 10;
	}

	str = malloc(len + 1);
	if (str == NULL)
		return (NULL);
	while (x != 0)
	{
		str[i] = (x % 10) + '0';
		x /= 10;
		i++;
	}

	str[i] = '\0';
	reverse_array(str, len);
	return (str);
}

/**
 * reverse_array - a function that reverses the content of an array of integers
 * @n: number of elemets of the array
 * @a: pointer variable
 *
 * Return: (0) success
 */

void reverse_array(char *a, int n)
{
	int i;
	char temp;

	for (i = 0; i < (n / 2); i++)
	{
		temp = a[i];
		a[i] = a[(n - 1) - i];
		a[(n - 1) - i] = temp;
	}
}

/**
 * _isalpha - checks lowercase character
 * @c: The character to be checked
 * Returns 0 if 'c' is lowercase or uppercase
 * Returns 1 otherwise
 *
 * Return: Always (0) Success
 */

int _isalpha(int c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
	{
		return (0);
	}
	else
	{
		return (1);
	}
}
