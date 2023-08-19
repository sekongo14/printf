#include "main.h"

/**
 * printf_char - print a char
 * @val: argument
 * Return: 1
 */

int printf_char(va_list val)
{
	char s;

	va_arg(val, int);
	_putchar(s);
	return (1);
}

