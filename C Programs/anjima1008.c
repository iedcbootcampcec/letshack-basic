//program to find the largest among 3 numbers



#include <stdio.h>
int main()
{
    int num1, num2, num3;
    printf(" Enter the number1 = ");
    scanf("%d", &num1);
    printf("\n Enter the number2 = ");
    scanf("%d", &num2);
    printf("\n Enter the number3 = ");
    scanf("%d", &num3);
    if (num1 > num2)
    {
        if (num1 > num3)
        {
            printf("\n Largest number = %d \n",num1);
        }
        else
        {
            printf("\n Largest number = %d \n",num3);
        }
    }
    else if (num2 > num3)
    {
        printf("\n Largest number = %d \n",num2);
    }
    else
    {
        printf("\n Largest number = %d \n",num3);
    }
    return 0;
}
