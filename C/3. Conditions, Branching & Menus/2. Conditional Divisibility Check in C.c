/*
Write a program that asks a number and test the number whether it is multiple of 5,
divisible by 7 but not by eleven.
*/

#include <stdio.h>

int main() {
    int num;
    printf("Enter a number :");
    scanf("%d", &num);

    if(num%5==0&&num%7==0&&num%11!=0)
        {printf("Yes\n");}
    else{printf("No\n");}

    return 0;
}
