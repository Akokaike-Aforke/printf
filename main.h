#ifndef MAIN_H
#define MAIN_H
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include <string.h>

int _printf(const char *format, ...);
void getcharacter(char *copy, char c, unsigned int *j);
void get_word_num(char *copy, char *word, unsigned int *j);
char *itoa(int num, char *str, int base);
<<<<<<< HEAD
char *get_bin(int dec_num);
=======
char *get_other(char c);
>>>>>>> 00ea282e859eb1a1a88fdef700fcb65374e3c93a

#endif /* MAIN_H */
