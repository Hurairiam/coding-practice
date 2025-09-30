/* Pattern 3: Right-Angled Pyramid of Stars (i+j<=rows)

     *
    * *
   * * *
  * * * *
 * * * * *

 */

#include<stdio.h>
int main()
{
    int i, j, rows=5;
    for(i=1; i<=rows; i++)
    {for(j=1; j<=rows; j++)
    {
        if(i+j<=rows){printf(" ");}
        else{printf("* ");}
    }
    printf("\n");
    }
 return 0;

}
