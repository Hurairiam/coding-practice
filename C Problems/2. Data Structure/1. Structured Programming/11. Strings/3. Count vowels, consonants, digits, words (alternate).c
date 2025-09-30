//Write a C program to find the number of vowels, consonants, digits and words in a string.

#include <stdio.h>

int main() {
    char str[200];
    char *p;  
    int vowels = 0, consonants = 0, digits = 0, words = 0;

    printf("Enter a string: ");
    gets(str); // For practice only; unsafe in real apps

    p = str; // Pointer to start of string

    if (*p != '\0' && *p != ' ')
        words++;

    for (; *p != '\0'; p++) {
        char ch = *p;

        if (ch >= 'A' && ch <= 'Z') {
            ch = ch + 32;
        }

        if (ch >= 'a' && ch <= 'z') {
            if (ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u')
                vowels++;
            else
                consonants++;
        }
        else if (ch >= '0' && ch <= '9') {
            digits++;
        }
        else if (ch == ' ' && *(p + 1) != ' ' && *(p + 1) != '\0') {
            words++;
        }
    }

    printf("\nVowels: %d", vowels);
    printf("\nConsonants: %d", consonants);
    printf("\nDigits: %d", digits);
    printf("\nWords: %d\n", words);

    return 0;
}
