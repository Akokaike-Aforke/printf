#include <string.h>
#include "main.h"
/**
 * _printf - print format strings
 * @format: string to be formatted
 * Return: return int
 */

int _printf(const char *format, ...)
{
	int len1, i, j = 0;
	va_list spec;
	char *copy;

	va_start(spec, format);
	len1 = strlen(format);
	copy = (char *)malloc(len1 + 1);
	for (i = 0; i < len1; i++)
	{
		if (format[i] != '%')
		{
			copy[j] = format[i];
			j++;
		}
		else
		{
			i++;
			if (format[i] == '%')
			{
				copy[j] = '%';
				j++;
			}
		}
	}
	copy[j] = '\0';
	va_end(spec);
	write(1, copy, j);
	return (strlen(copy));
}
