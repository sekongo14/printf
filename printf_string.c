#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include<string.h>

/**
 * printf_string - print a string.
 * @s: pointer to string
 * Return: the length of the string.
 */

int printf_string(const char *s)
{
	int i, len;

	if (s == NULL)
	{
		s = "(null)";
	}
	len = strlen(s);

	for (i = 0; i < len; i++)
	{
		_putchar(s[i]);
	}

	return (len);
}
