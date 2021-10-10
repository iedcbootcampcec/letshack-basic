#include <stdio.h>
#include <conio.h>
#include <string.h>

int main()
{
    char a[100];
    int b;
    printf("Enter a string : ");
    gets(a);
    b=strlen(a);

    for (int i=0;i<b;i++)
    {
        if (a[i]!=a[b-i-1])
        {
            printf("Its not a pallendrome");
            break;
        }
    
        if (i==b-i-1)
        {
            printf("Its a pallendrome");
            break;
        }

    }
    getch();
}