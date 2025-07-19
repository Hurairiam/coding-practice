/* Pattern 1: Right-Angled Triangle (Left-Aligned) - Static Numbers

1
2 2
3 3 3
4 4 4 4
5 5 5 5 5

*/

#include <stdio.h>
int main()
{
    int rows, i, j;
    printf("Enter number of rows : ");
    scanf("%d",&rows);

    for(int i=1; i<=rows; i++)
        {
            for(int j = 1; j <= i; j++)
            {
            printf("%d ", j);
            }
        printf("\n");
    }
    return 0;
}
