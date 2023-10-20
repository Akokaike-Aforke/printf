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
	char buffer[1024];
	size_t copy_length;

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
				get_w(copy, va_arg(spec, char *), &j);
			else if (format[i] == 'd' || format[i] == 'i')
				get_w(copy, int_str(va_arg(spec, int)), &j);
			else if (format[i] == 'b')
				get_w(copy, get_bin(va_arg(spec, int)), &j);
			else if (format[i] == 'x')
				get_w(copy, hex_l(va_arg(spec, unsigned int)), &j);
			else if (format[i] == 'X')
				get_w(copy, hex_u(va_arg(spec, unsigned int)), &j);
			else if (format[i] == 'o')
				get_w(copy, get_oct(va_arg(spec, unsigned int)), &j);
		}
}
	copy[j] = '\0';
	va_end(spec);
	copy_length = strlen(copy);
	memcpy(buffer, copy, copy_length);
	write(1, buffer, copy_length);
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
 * get_w - gets words
 * @copy: stores words
 * @word: word to be copied
 * @j: position of character
 * Return - void
 */
void get_w(char *copy, char *word, unsigned int *j)
{
	copy[*j] = '\0';
	copy = realloc(copy, strlen(word) + *j);
	strcat(copy, word);
	*j += strlen(word);
}
/**
 * get_other - gets words
 * @c: character
 * Return: a string
 */
char *get_other(char c)
{
	char *new_word = malloc(3);

	new_word[0] = '%';
	new_word[1] = c;
	new_word[2] = '\0';
	return (new_word);
}

/**
 * get_bin - converts decimal to binary
 * @dec_num: decimal to be converted
 * Return: a string
 */
char *get_bin(int dec_num)
{
	int i;
	int j;
	char *num;
	char *final_num;

	j = 0;
	num = (char *) malloc(sizeof(char) * j + 1);
	for (i = dec_num; i > 0; i /= 2)
	{
		num[j] = '0' + (i % 2);
		j++;
		num = realloc(num, sizeof(char) * j + 1);
	}
	num[j] = '\0';
	final_num = (char *) malloc(sizeof(num));
	final_num = my_strrev(num);
	return (final_num);
}
