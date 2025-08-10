//Write a C program to make a copy of a given string without using strcpy library function.

#include <stdio.h>

int main() {
    char source[100], copy[100];

    printf("Enter a string: ");
    fgets(source, sizeof(source), stdin);

    int i;
    // Copy character by character using for loop
    for (i = 0; source[i] != '\0'; i++) {
        copy[i] = source[i];
    }
    copy[i] = '\0';  // Null terminate

    printf("Copied string: %s", copy);

    return 0;
}
