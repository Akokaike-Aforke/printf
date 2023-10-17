#include "main.h"
<<<<<<< HEAD
/**
 * strrev - reverses a string
 * @word: string to be reversed
 * Return: a string
 */
char *strrev(char *word)
{
	int i;
	int j;
	char *rev = (char *)malloc(10);

	j = 0;

	for (i = strlen(word) - 1; i >= 0; i--)
	{
		rev[j] = '\0' + word[i];
		j++;
	}
	rev[j] = '\0';
	return (rev);
=======
char *my_strrev(char *word)
{
    int i;
    int j;
    j = 0;
    char *rev = (char*)malloc(sizeof(char) * j + 1);
    if(rev == NULL)
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
    return rev;
>>>>>>> 96829319c2101b16ecf93be222c0b6f5a8433295
}
