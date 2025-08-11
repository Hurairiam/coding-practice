/*Create a structure called "Car" that will hold information such as the car ID, model name, and daily
rental rate. Develop a C program that allows for the input of information for three cars, computes the
overall rental cost for a given duration in days, and presents the findings.*/

#include<stdio.h>

typedef struct car
{
    int carID;
    char modelName[50];
    float dailyRate;
}car;

int main()
{   int i, days;
    float overall;
    car hold[3];
    printf("Enter information : \n");
    printf("How many days are you going to rent for : ");
    scanf("%d",&days);

    for(int i=0; i<3; i++)
    {
        printf("Details for car no %d:\n", i+1);
        printf("Car ID: ");
        scanf("%d",&hold[i].carID);
        printf("Model Name: ");
        scanf("%s", hold[i].modelName);
        printf("Daily Rental Rate : ");
        scanf("%f",&hold[i].dailyRate);
    }
        for(int i=0; i<3; i++)
    {
        overall=hold[i].dailyRate*days;

        printf("Car ID: %d ", hold[i].carID);

        printf("Model Name: %s ", hold[i].modelName);

        printf("Overall Rental Cost for %d days: %.2f\n", days, overall);
    }
    return 0;
}
