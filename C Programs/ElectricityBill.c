#include<stdio.h>
struct Bill
{
    char firstName[10];
    char lastName[10];
    char Address[20];
    float previousUnit;
    float presentUnit;
};

float generateBill(struct Bill temp)
{
    float diff;
    diff = temp.presentUnit - temp.previousUnit;
    if(diff > 20)
    {
        return diff*4.75;
    }
    else
    {
        return 20*4.75+(diff-20)*7.75;
    }
}
void main()
{
    struct Bill bill, *ptrEmp;
    ptrEmp = &bill;

    printf("Fill up the following: \n");

    printf("First Name: ");
    scanf("%s", &ptrEmp->firstName);

    printf("Last Name: ");
    scanf("%s", &ptrEmp->lastName);

    printf("Address: ");
    scanf(" %[^\t\n]s", &ptrEmp->Address);

    printf("Previous Unit: ");
    scanf("%f",&ptrEmp->previousUnit);

    printf("Present Unit: ");
    scanf("%f",&ptrEmp->presentUnit);

    printf("\a\n\n***********Electricity Bill***************\n\n\a");

    printf("Name: %s %s",ptrEmp->firstName,ptrEmp->lastName);
    printf("\nAddress: %s",ptrEmp->Address);
    printf("\nPrevious Unit: %.3f       Current Unit: %.3f",ptrEmp->previousUnit,ptrEmp->presentUnit);
    printf("\nCost: %.3f Rs\n\n", generateBill(bill));
}
