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
	char *copy;
	char digits[10];

	va_start(spec, format);
	copy = (char *)malloc(strlen(format) + 1);
	for (i = 0; i < strlen(format); i++)
	{
		if (format[i] != '%')
			getcharacter(copy, format[i], &j);
		else
		{
			i++;
			if (format[i] == '%')
				getcharacter(copy, format[i], &j);
			else if (format[i] == 'c')
				getcharacter(copy, va_arg(spec, int), &j);
			else if (format[i] == 's')
				get_word_num(copy, va_arg(spec, char *), &j);
			else if (format[i] == 'd' || format[i] == 'i')
				get_word_num(copy, itoa(va_arg(spec, int), digits, 10), &j);
		}
	}
	copy[j] = '\0';
	va_end(spec);
	write(1, copy, j);
	free(copy);
	return (j);
}
/**
 * getcharacter - gets character
 * @copy:copies character
 * @c: charactet to be copied
 * @j: position of character
 */
void getcharacter(char *copy, char c, unsigned int *j)
{
	copy[*j] = c;
	(*j)++;
}
/**
 * get_word_num - gets words
 * @copy: stores words
 * @word: word to be copied
 * @j: position of character
 * Return - void
 */
void get_word_num(char *copy, char *word, unsigned int *j)
{
	copy[*j] = '\0';
	copy = realloc(copy, strlen(word) + *j);
	strcat(copy, word);
	*j += strlen(word);
}
