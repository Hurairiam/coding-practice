#include<stdio.h>
//printf("");

int main()
{
    int r1, r2, c1, c2, i, j, k;
    int m1[50][50], m2[50][50], pro[50][50]={0};

    printf("Enter the number of rows and columns of the first matrix : ");
    scanf("%d%d",&r1, &c1);
    printf("Enter the number of rows and columns of the second matrix : ");
    scanf("%d%d",&r2, &c2);

    if(c1!=r2){printf("Matrix multiplication not possible");}
    else
    {
       printf("Enter the elements of the first matrix : ");
       for(i=0; i<r1; i++)
       {
          for(j=0; j<c1; j++)
          {scanf("%d", &m1[i][j]);}
       }
              printf("Enter the elements of the second matrix : ");
       for(i=0; i<r2; i++)
       {
          for(j=0; j<c2; j++)
          {scanf("%d", &m2[i][j]);}
       }

       for(i=0; i<r1; i++)
       {
          for(j=0; j<c2; j++)
            {for(k=0; k<c1; k++)
          {pro[i][j]+=m1[i][k]*m2[k][j];}}
       }
              printf("The resultant matrix is : ");
       for(i=0; i<r1; i++)
       {
          for(j=0; j<c2; j++)
          {printf("%d ", pro[i][j]);}
           printf("\n");}
    }
     }
    return 0;

}
