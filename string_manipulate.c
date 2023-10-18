#include "main.h"
/**
 * my_strrev - reverses a string
 * @word: string to be reversed
 * Return: a string
 */
char *my_strrev(char *word)
{
	int i;
	int j;
	char *rev;

	j = 0;
	rev = (char *)malloc(sizeof(char) * j + 1);
	if (rev == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}
	for (i = strlen(word) - 1; i >= 0; i--)
	{
		rev[j] = '\0' + word[i];
		j++;
		rev = realloc(rev, sizeof(char) * j + 1);
	}
	rev[j] = '\0';
	return (rev);
};
/**
 * get_hex- gets uppercase hex
 * @dec_num: number to conver
 * Return: a string
 */


char *get_hex(unsigned int dec_num)
{
    unsigned int i;
     int j;
     j = 0;
    char * num = (char *) malloc(sizeof(char) * j + 1);
     if(num == NULL)
    {
        perror("Memory allocation failed");
        exit(1);

    }
    char *final_num;
    for (i = dec_num; i > 0; i/=16)
    {
        if(i % 16 == 10)
        num[j] = 'A';
        else if(i % 16 == 11)
        num[j] = 'B';
        else if(i % 16 == 12)
        num[j] = 'C';
        else if(i % 16 == 13)
        num[j] = 'D';
        else if(i % 16 == 14)
        num[j] = 'E';
        else if(i % 16 == 15)
        num[j] = 'F';
        else
        num[j] = '0' + (i % 16);
        j++;
        num = realloc(num, sizeof(char) * j + 1);
    }
    num[j] = '\0';

    final_num = (char *) malloc(sizeof(num)* j + 1);
     if(final_num == NULL)
    {
        perror("Memory allocation failed");
        exit(1);

    }
    final_num = my_strrev(num);
    free(num);
    return final_num;

}
/**
 * get_hex2- gets lowercase hex
 * @dec_num: number to conver
 * Return: a string
 */

char *get_hex2(unsigned int dec_num)
{
    unsigned int i;
     int j;
     j = 0;
    char * num = (char *) malloc(sizeof(char) * j + 1);
     if(num == NULL)
    {
        perror("Memory allocation failed");
        exit(1);

    }
    char *final_num;
    for (i = dec_num; i > 0; i/=16)
    {
        if(i % 16 == 10)
        num[j] = 'a';
        else if(i % 16 == 11)
        num[j] = 'b';
        else if(i % 16 == 12)
        num[j] = 'c';
        else if(i % 16 == 13)
        num[j] = 'd';
        else if(i % 16 == 14)
        num[j] = 'e';
        else if(i % 16 == 15)
        num[j] = 'f';
        else
        num[j] = '0' + (i % 16);
        j++;
        num = realloc(num, sizeof(char) * j + 1);
    }
    num[j] = '\0';

    final_num = (char *) malloc(sizeof(num)* j + 1);
     if(final_num == NULL)
    {
        perror("Memory allocation failed");
        exit(1);

    }
    final_num = my_strrev(num);
    free(num);
    return final_num;

}

