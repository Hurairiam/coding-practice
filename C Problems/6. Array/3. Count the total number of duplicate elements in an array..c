/*
Write a program in C to count the total number of duplicate elements in an array.
Test Data :
Input the number of elements to be stored in the array :3
Input 3 elements in the array :
element - 0 : 5
element - 1 : 1
element - 2 : 1
Expected Output :
Total number of duplicate elements found in the array is : 1
*/

#include<stdio.h>
int main()
{
     int i, j, n, num[100], count=0;

    printf("Number of elements to be stored in the array : ");
    scanf("%d", &n);

for(i=0; i<n; i++)
     {
         printf("\nElement - %d : ", i+1);
         scanf("%d", &num[i]);
     }

for(i=0; i<n; i++)
    { for(j=i+1; j<n; j++)
     {
         if(num[i]==num[j])
         { count++; break;}
     }
    }

printf("/nTotal number of duplicate elements found in the array is : %d ", count);

return 0;
}
