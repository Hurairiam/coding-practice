/*
Write a program to find the largest and smallest among three entered numbers and also
display whether the identified largest/smallest number is even or odd.
*/

#include <stdio.h>

int main() {
    int a, b, c, largest, smallest;
    printf("Enter three numbers: ");
    scanf("%d %d %d", &a, &b, &c);

    // Find largest
     if(a>=b&&a>=c){largest=a;}
else if(b>=a&&b>=c){largest=b;}
     else{largest=c;}
    printf("Largest: %d - ", largest);

     if(largest%2==0) {printf("Even\n");}
     else{printf("Odd\n");}

    // Find smallest
     if(a<=b&&a<=c){smallest = a;}
else if(b<=a&&b<=c){smallest = b;}
     else{smallest = c;}
    printf("Smallest: %d - ", smallest);

     if(smallest%2==0){printf("Even\n");}
     else{printf("Odd\n");}

    return 0;
}
