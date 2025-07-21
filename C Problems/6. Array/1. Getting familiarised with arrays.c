//Arrays in c
#include<stdio.h>
int main()
{
int num[10000]/*={1, 2, 3, 4, 5}*/, i, j;
//num[2]=30;

/*
printf("Enter series number : ");
scanf("%d",&i);
printf("%d",num[i]);
*/

for(i=0; i<1000; i++)
{
    num[i]=i+1;
}
printf("Enter series number : ");
scanf("%d",&j);
printf("%d",num[j]);


return 0;
}
