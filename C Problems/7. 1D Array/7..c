#include<stdio.h>

int main()
{
    int i, j, n, num[100], dupliCount=0;
    int visited[100]={0};
    printf("Input the number of elements to be stored in the array : ");
    scanf("%d", &n);
    printf("\nInput %d elements in the array :\n", n);

    for(i=0; i<n; i++)
    {
        printf("element - %d : ", i);
        scanf("%d", &num[i]);
    }

    for(i=0; i<n; i++)
    {
        if(visited[i])
            continue;

        int dupliCount=1;

        for(j=i+1; j<n; j++)
        {
            if(num[i]==num[j])
            {
                dupliCount++;
                visited[j]=1;
            }
        }

        if(dupliCount>1)
            dupliCount++;
    }

    printf("Total number of duplicate elements found in the array is : %d\n", dupliCount);

    return 0;
}
