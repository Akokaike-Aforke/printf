/**#include <string.h>
#include "main.h"*/
/**
 * _printf - print format strings
 * @format: string to be formatted
 * Return: return int
 */

/*int _printf(const char *format, ...)
{
	int len1, len2, i, j = 0;
	va_list spec;
	char *copy;
	const char *newWord;

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
			else if (format[i] == 'c')
			{
				copy[j] = va_arg(spec, int);
				j++;
			}
			else if (format[i] == 's')
			{
				copy[j] = '\0';
				newWord = va_arg(spec, char*);
				len2 = strlen(newWord);
				copy = realloc(copy, len1 + len2);
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
}*/
