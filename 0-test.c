#include <string.h>
#include "main.h"
/**
 * _printf - print format strings
 * @format: string to be formatted
 * Return: return int
 */

int _printf(const char *format, ...)
{
	unsigned int i, j = 0;
	va_list spec;
	char *copy, *newWord;

	va_start(spec, format);
	copy = (char *)malloc(strlen(format) + 1);
	for (i = 0; i < strlen(format); i++)
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
			else if (format[i] == 'c')
			{
				copy[j] = va_arg(spec, int);
				j++;
			}
			else if (format[i] == 's')
			{
				copy[j] = '\0';
				newWord = va_arg(spec, char*);
				copy = realloc(copy, strlen(format) + strlen(newWord));
				strcat(copy, newWord);
				j += strlen(newWord);
			}
		}
	}
	copy[j] = '\0';
	va_end(spec);
	write(1, copy, j);
	free(copy);
	return (strlen(copy));
}
