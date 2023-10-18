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
}
/**
 * hex_u - gets uppercase hex
 * @dec_num: number to conver
 * Return: a string
 */
char *hex_u(unsigned int dec_num)
{
	unsigned int i;
	int j;
	char *num, *final_num;

	j = 0;
	num = (char *) malloc(sizeof(char) * j + 1);
	if (num == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}
	for (i = dec_num; i > 0; i /= 16)
	{
		if (i % 16 == 10)
			num[j] = 'A';
		else if (i % 16 == 11)
			num[j] = 'B';
		else if (i % 16 == 12)
			num[j] = 'C';
		else if (i % 16 == 13)
			num[j] = 'D';
		else if (i % 16 == 14)
			num[j] = 'E';
		else if (i % 16 == 15)
			num[j] = 'F';
		else
			num[j] = '0' + (i % 16);
		j++;
		num = realloc(num, sizeof(char) * j + 1);
	}
	num[j] = '\0';
	final_num = (char *)malloc(sizeof(num) * j + 1);
	if (final_num == NULL)
	{
		perror("Memory allocation failed");
	}
	final_num = my_strrev(num);
	free(num);
	return (final_num);
}
/**
 *hex_l -  gets lowercase hex
 * @dec_num: number to conver
 * Return: a string
 */
char *hex_l(unsigned int dec_num)
{
	unsigned int i;
	int j;
	char *num, *final_num;

	j = 0;
	num = (char *) malloc(sizeof(char) * j + 1);
	if (num == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}
	for (i = dec_num; i > 0; i /= 16)
	{
		if (i % 16 == 10)
			num[j] = 'a';
		else if (i % 16 == 11)
			num[j] = 'b';
		else if (i % 16 == 12)
			num[j] = 'c';
		else if (i % 16 == 13)
			num[j] = 'd';
		else if (i % 16 == 14)
			num[j] = 'e';
		else if (i % 16 == 15)
			num[j] = 'f';
		else
			num[j] = '0' + (i % 16);
		j++;
		num = realloc(num, sizeof(char) * j + 1);
	}
	num[j] = '\0';
	final_num = (char *)malloc(sizeof(num) * j + 1);
	if (final_num == NULL)
	{
		perror("Memory allocation failed");
		exit(1);
	}
	final_num = my_strrev(num);
	free(num);
	return (final_num);
}
