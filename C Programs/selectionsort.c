#include<stdio.h>
void main()
{
  int a[100],i,j,n,position,t;
  printf("enter number of elements \n");
  scanf("%d",&n);
  printf("enter %d integers\n",n);
  for(i=0;i<n;i++)
   {
     scanf("%d",&a[i]);
   }
  for(i=0;i<(n-1);i++)
   {
     position=i;
     for(j=i+1;j<n;j++)
      {
        if(a[position]>a[j])
          position=j;
      }
      if(position!=i)
        {
          t=a[i];
          a[i]=a[position];
          a[position]=t;
        }
   }
   printf("sorted list in ascending order:\n");
   for(i=0;i<n;i++)
    {
      printf("%d\n",a[i]);
    }
}
