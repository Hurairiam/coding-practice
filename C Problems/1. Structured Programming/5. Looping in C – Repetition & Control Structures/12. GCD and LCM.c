//Write a program to find GCD (greatest common divisor or HCF) and LCM (least common multiple) of two numbers.

#include<stdio.h>
int main()
{   int a, b, gcd, lcm, min, i;
    printf("Enter two numbers : ");
    scanf("%d %d", &a, &b);
    if(a>b){min=b;}
       else{min=a;};

    for(i=1; i<=min ; i++)
    {
        if(a%i==0&&b%i==0)
        {gcd=i;}
    }
    lcm=(a*b)/gcd;
   printf("GCD = %d, LCM = %d", gcd, lcm);

   return 0;
}
