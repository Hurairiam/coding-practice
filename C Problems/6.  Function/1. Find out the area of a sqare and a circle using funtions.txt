//Find out the area of a circle and a sqaure

#include <stdio.h>

float squareArea();
float circleArea();

int main() {
    int cho;
    printf("Choose option\n1. Area of Circle\n2. Area of Square\n");
    scanf("%d", &cho);

    (cho == 1) ? circleArea() : (cho == 2) ? squareArea() : printf("Invalid choice\n");

    return 0;
}

float squareArea() {
    float a;
    printf("Enter side of the square: ");
    scanf("%f", &a);
    float area = a * a;
    printf("Area of the square is %.3f\n", area);
    return area;
}

float circleArea() {
    float r;
    printf("Enter radius of the circle: ");
    scanf("%f", &r);
    float area = 3.1416f * r * r;
    printf("Area of the circle is %.3f\n", area);
    return area;
}
