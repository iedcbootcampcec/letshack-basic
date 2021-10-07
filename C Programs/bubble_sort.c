#include <stdio.h>
#include <conio.h>
void main()
{
    int a ,i,j,swap;
    printf("Enter the number of items to store :");
    scanf("%d",&a);
    int b[a];
    for (int i=0;i<a;i++)
    {
        printf("Enter the %dth number :",i+1);
        scanf("%d",&b[i]);
    }
    for (i=0;i<a-1;i++)  
    {
        for (j=0;j<a-i-1;j++)
        {
            if (b[j]>b[j+1])
            {
                swap=b[j];
                b[j]=b[j+1];
                b[j+1]=swap;
            }
        }
    }
    for (int k=0;k<a;k++)
    {
        printf("%d",b[k]);
    }
    getch();
}
