#include <stdio.h>
#include <string.h>

int main()
{
    int a[100], visited[100];

    memset(visited, 0, 100*sizeof(visited[0]));

    int n;
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &a[i]);
    }
    int count = 0;
    for(int i=0; i<n; i++){
        if(visited[a[i]]==0){
            for(int j=i+1; j<n; j++){
                if(a[i]==a[j]){
                    count++;
                    visited[a[i]]++;
                    break;
                }
            }
        }
    }

    printf("Number of duplicate elements = %d\n", count);

    for(int i=0; i<=99; i++){
        if(visited[i]>0){
            printf("%d ", i);
        }
    }
    printf("\n");

}
