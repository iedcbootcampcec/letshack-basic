
#include <stdio.h>
#include <string.h>
void main()
{
    int a,b,c,d;
    int *p1,*p2;
    p1=&c;
    p2=&d;
    printf("enter two numbers to be swapped by call by value");
    scanf("%d%d",&a,&b);
    printf("enter two numbers to be swapped by call by reference");
    scanf("%d%d",&c,&d);
    swap1(a,b);
    swap2(p1,p2);
    printf("the result after swapping is %d,%d",c,d);
}

void swap1(int m,int n)
{
   int temp;
   temp=m;
   m=n;
   n=temp;
   printf("swapped values are %d,%d\n",m,n);
}

void swap2(int *p1,int *p2)
{
    int temp;
    temp=*p1;
    *p1=*p2;
    *p2=temp;
}    


