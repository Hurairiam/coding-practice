/* 
 Write a C program that takes two strings as input and displays the concatenated string putting the lengthier one at the end in uppercase without using strcat library function
*/

#include <stdio.h>

void toUpperCase(char str[]) {
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] >= 'a' && str[i] <= 'z')
            str[i] = str[i] - ('a' - 'A');
    }
}

int length(char str[]) {
    int len = 0;
    for (; str[len] != '\0'; len++);
    return len;
}

int main() {
    char s1[100], s2[100], result[200];

    printf("Enter first string: ");
    fgets(s1, sizeof(s1), stdin);
    printf("Enter second string: ");
    fgets(s2, sizeof(s2), stdin);

    // Remove newline if present
    int len1 = length(s1);
    if (s1[len1 - 1] == '\n') s1[len1 - 1] = '\0';
    len1 = length(s1);

    int len2 = length(s2);
    if (s2[len2 - 1] == '\n') s2[len2 - 1] = '\0';
    len2 = length(s2);

    if (len1 >= len2) {
        toUpperCase(s1);
        int i, j;
        // Copy shorter string first
        for (i = 0; i < len2; i++) result[i] = s2[i];
        // Append uppercase longer string
        for (j = 0; j < len1; j++) result[i + j] = s1[j];
        result[i + j] = '\0';
    } else {
        toUpperCase(s2);
        int i, j;
        for (i = 0; i < len1; i++) result[i] = s1[i];
        for (j = 0; j < len2; j++) result[i + j] = s2[j];
        result[i + j] = '\0';
    }

    printf("Concatenated string: %s\n", result);

    return 0;
}