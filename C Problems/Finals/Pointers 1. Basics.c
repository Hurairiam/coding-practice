#include <stdio.h>

int main() {
    int x = 99;
    int *pnt = &x;

    printf("x = %d\n", x);
    printf("pnt (address of x) = %p\n", pnt);
    printf("*pnt (value at that address) = %d\n", *pnt);
    printf("&pnt (address of the pointer itself) = %p\n", &pnt);

    return 0;
}
