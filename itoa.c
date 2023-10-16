#include <stdio.h>
#include <stdlib.h>

char *itoa(int num, char *str, int base) {
    int i;
    int isNegative;
    int start;
    int end;

    i = 0;
    isNegative = 0;

    if (base < 2 || base > 36) {
        *str = '\0';
        return str;
    }

    if (num < 0 && base == 10) {
        isNegative = 1;
        num = -num;
    }

    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num /= base;
    }

    if (isNegative && base == 10) {
        str[i++] = '-';
    }

    str[i] = '\0';

    start = 0;
    end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    return str;
}
