/* 
 Write a C program that takes two strings as input and displays the concatenated string putting the lengthier one at the end in uppercase without using strcat library function
*/

#include <stdio.h>

int main() {
    char s1[100], s2[100], *shorter, *longer;
    int len1 = 0, len2 = 0;
    char *p;

    gets(s1);
    gets(s2);

    // Calculate lengths
    for (p = s1; *p != '\0'; p++) len1++;
    for (p = s2; *p != '\0'; p++) len2++;

    // Decide shorter and longer
    if (len1 <= len2) {
        shorter = s1; longer = s2;
    } else {
        shorter = s2; longer = s1;
    }

    // Convert longer string to uppercase in place
    for (p = longer; *p != '\0'; p++) {
        if (*p >= 'a' && *p <= 'z') *p = *p - 32;
    }

    // Print shorter then uppercase longer together
    printf("%s%s\n", shorter, longer);

    return 0;
}
