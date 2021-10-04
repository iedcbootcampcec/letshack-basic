#include<stdio.h>
int reverse(int x)
{
   int rem, rev=0;
   while(x!=0)
   {
       rem=x%10;
       rev=rev*10+rem;
       x/=10;
   }
   printf("Reverse of the number: %d\n",rev);
}
int main()
{
    int i;
    printf("Enter a number: \n");
    scanf("%d",&i);
    reverse(i);
    return 0;
}
