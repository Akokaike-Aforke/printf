#include "main.h"
int _printf(const char * format, ...)
{
    int strLength;
    va_list spec;
    va_start(spec, format);
    strLength = strlen(format);
    char *copy;
    const char *newWord;

    int i;
    int j = 0; 

    copy = (char *)malloc(strLength + 1);

    if (copy == NULL) {
        perror("malloc");
        return 1;
    }

    for (i = 0; i < strlen(format); i++) {
        if (format[i] != '%') {
            copy[j] = format[i];
            j++;
        } 
        else 
        {
            i++;
            if(format[i] == '%')
            {
               copy[j] = '%';
             j++;
            }
            else if(format[i] == 'c')
          {
          copy[j] = va_arg(spec, int);
          j++;
          }
          else if(format[i] == 's')
          {
            copy[j] = '\0';
            newWord = va_arg(spec, char*);
            copy = realloc(copy, strLength + strlen(newWord));
            strcat(copy, newWord);
            j += strlen(newWord);
          }
        }
    }

    copy[j] = '\0';
        va_end(spec);
    int bites = write(1, copy, j);
    free(copy);
    return strlen(copy);
}

