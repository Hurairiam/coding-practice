//Read n numbers into an array and print them.

#include<stdio.h>
int main()
{
    int i, n, num[10000];
     printf("How many numbers do you want to input?  ");
     scanf("%d", &n);

     for(i=0; i<n; i++)
     {
         printf("Enter term %d : ", i+1);
         scanf("%d", &num[i]);
     }
      for(i=0; i<n; i++)
     {
         printf("%d ", num[i]);

     }

return 0;
}
