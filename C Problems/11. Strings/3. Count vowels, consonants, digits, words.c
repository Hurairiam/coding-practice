//Write a C program to find the number of vowels, consonants, digits and words in a string.

#include <stdio.h>
#include <ctype.h>

int main() {
    char str[200];
    int vowels = 0, consonants = 0, digits = 0, words = 0;
    int inWord = 0;

    printf("Enter a string: ");
    fgets(str, sizeof(str), stdin);

    for (int i = 0; str[i] != '\0'; i++) {
        char ch = str[i];

        if ((ch >= 'A' && ch <= 'Z') || (ch >= 'a' && ch <= 'z')) {
            char lower = tolower(ch);
            if (lower == 'a' || lower == 'e' || lower == 'i' || lower == 'o' || lower == 'u')
                vowels++;
            else
                consonants++;

            if (!inWord) {
                words++;
                inWord = 1;
            }
        }
        else if (ch >= '0' && ch <= '9') {
            digits++;
            inWord = 0;
        }
        else {
            inWord = 0;
        }
    }

    printf("Vowels: %d\nConsonants: %d\nDigits: %d\nWords: %d\n", vowels, consonants, digits, words);

    return 0;
}
