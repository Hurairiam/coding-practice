/* 
 Write a C program that takes two strings as input and displays the concatenated string putting the lengthier one at the end in uppercase without using strcat library function
*/

#include <stdio.h>

int main() {
    char s1[100], s2[100], result[200];
    char *p;
    int len1 = 0, len2 = 0;

    printf("Enter first string: ");
    gets(s1);

    printf("Enter second string: ");
    gets(s2);

    // Count length of s1 using pointer
    p = s1;
    while (*p != '\0') {
        len1++;
        p++;
    }

    // Count length of s2 using pointer
    p = s2;
    while (*p != '\0') {
        len2++;
        p++;
    }

    char *shorter, *longer;

    if (len1 <= len2) {
        shorter = s1;
        longer = s2;
    } else {
        shorter = s2;
        longer = s1;
    }

    // Convert longer string to uppercase in place
    p = longer;
    while (*p != '\0') {
        if (*p >= 'a' && *p <= 'z') {
            *p = *p - 32;
        }
        p++;
    }

    // Copy shorter string to result
    int i = 0;
    while (shorter[i] != '\0') {
        result[i] = shorter[i];
        i++;
    }

    // Append uppercase longer string to result
    int j = 0;
    while (longer[j] != '\0') {
        result[i] = longer[j];
        i++;
        j++;
    }
    result[i] = '\0';

    printf("Concatenated string: %s\n", result);

    return 0;
}
