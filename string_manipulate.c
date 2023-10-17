#include "main.h"
char *strrev(char *word)
{
    int i;
    int j;
    char *rev = (char*)malloc(10);
    j= 0;
    for (i = strlen(word) - 1; i >= 0; i--)
    {
        rev[j] = '\0' + word[i];
        j++;
    }
    rev[j] = '\0';
    return rev;
}
