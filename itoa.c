#include <stdio.h>
#include <stdlib.h>

char *itoa(int num, char *str, int base) {
    if (base < 2 || base > 36) {
        *str = '\0';
        return str;
    }

    int i = 0;
    int isNegative = 0;

    // Handle negative numbers for bases other than 10
    if (num < 0 && base == 10) {
        isNegative = 1;
        num = -num;
    }

    // Convert the number to a string in reverse order
    while (num != 0) {
        int rem = num % base;
        str[i++] = (rem > 9) ? (rem - 10) + 'a' : rem + '0';
        num /= base;
    }

    // Add the negative sign for base 10
    if (isNegative && base == 10) {
        str[i++] = '-';
    }

    str[i] = '\0';

    // Reverse the string
    int start = 0;
    int end = i - 1;
    while (start < end) {
        char temp = str[start];
        str[start] = str[end];
        str[end] = temp;
        start++;
        end--;
    }

    return str;
}

int main() {
    int number = -12345;
    char str[20]; // Ensure a sufficiently large buffer to hold the result
    itoa(number, str, 10);
    printf("Number as string: %s\n", str);
    return 0;
}

