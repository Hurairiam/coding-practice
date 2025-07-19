/* Pattern 2: Right-Angled Triangle (Right-Aligned)

      *
    * *
  * * *
* * * *

*/

#include <stdio.h>
int main() {
    int rows, i, j, s;
    printf("Enter number of rows : ");
    scanf("%d",&rows);

    for (int i = 1; i <= rows; i++) {
        for (int s =1; s<=rows-i; s++) {
            printf("  ");
        }
        for (int j=1; j<=i; j++) {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
