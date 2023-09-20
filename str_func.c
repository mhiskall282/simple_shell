<<<<<<< HEAD
#include "shell.h"
/**
 * _strcpy - Copie Source To Destination Char
 * @dest:Destination
 * @src:Source
 * Return: Copie Of Char *
 */
char *_strcpy(char *dest, char *src)
{
int i;

i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i++;
	}
dest[i] = '\0';
return (dest);
}
/**
 * _strcat - Concat Two String
 * @dest:First String
 * @src:Second String
 * Return:First String + Second String Char *
 */
char *_strcat(char *dest, char *src)
{
	char *s = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (*src != '\0')
	{
		*dest = *src;
		dest++;
		src++;
	}
	*dest = '\0';
	return (s);
}
/**
 * _strchr - Locate Charactere In String
 * @s:String Search In
 * @c:Char To Search For
 * Return: Pointer To Char*
 */
char *_strchr(char *s, char c)
{

	do		{

		if (*s == c)
			{
			break;
			}
		}	while (*s++);

return (s);
}
/**
 * _strncmp - Compare Amount (n) Of Characters Of Two Strings.
 * @s1: A String.
 * @s2: A String.
 * @n: Amount Of Characters To Compare.
 *
 * Return: 1 If The Strings Don't Match Otherwise 0
 */
int _strncmp(const char *s1, const char *s2, size_t n)
{
	size_t i;

	if (s1 == NULL)
		return (-1);
	for (i = 0; i < n && s2[i]; i++)
	{
		if (s1[i] != s2[i])
		{
			return (1);
		}
	}
	return (0);
}
/**
 * _strdup - Duplicate A String
 * @str:String
 * Return: Duplicate String Failed Null
 */
char *_strdup(char *str)
{
	size_t len, i;
	char *str2;

	len = _strlen(str);
	str2 = malloc(sizeof(char) * (len + 1));
	if (!str2)
	{
		return (NULL);
	}

	for (i = 0; i <= len; i++)
	{
		str2[i] = str[i];
	}

	return (str2);
=======
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
>>>>>>> main
}
