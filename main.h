#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

int _printf(const char *format, ...);
void getcharacter(char *copy, char c, unsigned int *j);
void get_word_num(char *copy, char *word, unsigned int *j);

#endif
