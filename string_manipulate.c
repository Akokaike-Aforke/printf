#include "main.h"
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
}
