//Write a C program to make a copy of a given string without using strcpy library function.

#include <stdio.h>

int main() {
    char str1[100], str2[100];
    int i;

    printf("Enter a string: ");
    gets(str1); // Using gets() for simplicity (unsafe in real applications)

    // Copy string manually
    for (i = 0; str1[i] != '\0'; i++) {
        str2[i] = str1[i];
    }
    str2[i] = '\0'; // Add null terminator

    printf("Original string: %s\n", str1);
    printf("Copied string: %s\n", str2);

    return 0;
}

