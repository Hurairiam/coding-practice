/*
Write a program to input a letter and display it in opposite case, i.e., if the given letter is in
upper case, display it in lower case and vice-versa
*/
#include <stdio.h>

int main()
{
    char ch;
    printf("Enter an alphabet : ");
    scanf(" %c", &ch);

     if(ch>='A'&&ch<='Z')
        {ch=ch+32;}
else if(ch>='a'&&ch<='z')
        {ch=ch-32;}

    printf("The opposite case is : %c\n", ch);
    return 0;
}
