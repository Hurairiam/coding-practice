/* Pattern 1: Right-Angled Triangle (Left-Aligned)

*
**
***
****
*****

*/

#include <stdio.h>
int main()
{
    int rows, i, j;
    printf("Enter number of rows : ");
    scanf("%d",&rows);

    for(int i=1; i<=rows; i++)
        {
            for(int j=1; j<=i; j++)
            {printf("*");}
        printf("\n");
    }
    return 0;
}
