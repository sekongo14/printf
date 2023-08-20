#include "main.h"

#include <stdio.h>
#include <stdarg.h>

/**
 * _printf - Custom printf function
 * @format: The format string
 * Return: Number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list args;

	va_start(args, format);

	int count = 0;
	const char *ptr = format;

	while (*ptr != '\0')
	{
		if (*ptr == '%')
		{
			ptr++; /* Move past the '%' */
			if (*ptr == '\0')
				break; /* End of format string */
			if (*ptr == 'c')
				int c = va_arg(args, int);

				putchar(c);
				count++;
			else if (*ptr == 's')
			{
				char *s = va_arg(args, char *);

				while (*s != '\0')
					putchar(*s);
					s++;
					count++;
			}
			else if (*ptr == '%')
				putchar('%');
				count++;
		}
		else
			putchar(*ptr);
			count++;
		ptr++;
	}
	va_end(args);
	return (count);
}
