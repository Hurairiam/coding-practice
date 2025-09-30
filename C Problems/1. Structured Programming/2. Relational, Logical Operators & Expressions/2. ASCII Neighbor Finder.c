/*
Write a C program to take a letter from the English alphabet as input and display both the
previous and the next letters with ASCII codes. Assume that input will always be chosen from B
to Y or b to y.
Sample Input : Enter a letter: d
Sample Output : Previous letter with ASCII: c 99
                Next letter with ASCII: e 101
*/

#include <stdio.h>

int main()
{
    char ch;
    printf("Enter an alphabet : ");
    scanf(" %c", &ch);
    printf("Previous letter with ASCII: %c %d\n", ch-1, ch-1);
    printf("Next letter with ASCII: %c %d\n", ch+1, ch+1);
    return 0;
}
