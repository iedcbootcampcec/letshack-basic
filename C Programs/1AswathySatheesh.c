#include<stdio.h>
int main()
{
   int count,temp,i,j,number[30];
   
   printf("How many numbers do you want to enter? :");
   scanf("%d",&count);
   
   printf("Enter %d numbers :\n",count);
   
   for(i=0;i<count;i++)
      scanf("%d",&number[i]);
   
   for(i=count-2;i>=0;i--)
   {
      for(j=0;j<=i;j++)
      {
         if(number[j]>number[j+1])
         {
            temp=number[j];
            number[j]=number[j+1];
            number[j+1]=temp;
         }
      }
   }
   int m;
   for(m=0;m<count;m++)
   {
      printf("%d ",number[m]);
   }   
   
}
