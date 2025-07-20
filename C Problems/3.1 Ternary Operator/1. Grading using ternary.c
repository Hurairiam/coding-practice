/*
Write a C program that:

Takes a student's score (0 to 100) as input.

Uses ternary operators to assign a performance category:

"Excellent" if score ≥ 90

"Good" if score ≥ 75

"Average" if score ≥ 50

"Poor" if score < 50

Use only ternary operators, no if-else allowed.

*/

#include<stdio.h>
int main()
{
    int score;
    printf("Enter your score : ");
    scanf("%d", &score);
    (score>=90)? printf("Excellent") : (score>=75)? printf("Good") : (score>=50)? printf("Average") : printf("Bad");
    return 0;

}
