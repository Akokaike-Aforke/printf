#include <string.h>
#include "main.h"
/**
 * _printf - print format strings
 * @format: string to be formatted
 * Return: return int
 */

int add(int x, int y);
 void getcharacter(char *copy, char c, unsigned int *j);
 void get_word_num(char *copy, char *word, unsigned int *j);

int _printf(const char *format, ...)
{
        unsigned int i, j = 0;
        va_list spec;
        static char *copy;
        char *newWord;
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
                        getcharacter(copy, '%', &j);
                        else if (format[i] == 'c')
                        getcharacter(copy,va_arg(spec, int), &j);
                        else if (format[i] == 's')
                        get_word_num(copy, va_arg(spec, char *), &j);
                        else if(format[i] == 'd' || format[i] == 'i')
                        get_word_num(copy, itoa(va_arg(spec, int), digits, 10), &j);
        copy[j] = '\0';
        va_end(spec);
        write(1, copy, j);
        free(copy);
        return (j);
}
        }
}
 void getcharacter(char *copy, char c, unsigned int *j)
        {
                copy[*j] = c;
                (*j)++;
        }
void get_word_num(char *copy, char *word, unsigned int *j)
{
        copy[*j] = '\0';
        copy = realloc(copy, strlen(word) + *j);
        strcat(copy, word);
        *j+=strlen(word);
        return (0);
}

