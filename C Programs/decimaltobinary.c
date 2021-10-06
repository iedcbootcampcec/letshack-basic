#include<stdio.h>
void main()
{ int a[20],n;
  int i;
  printf ("Enter the number n : ");
  scanf ("%d",&n);
  
  for( i=0;n>0;i++)
    {  
      a[i] = n%2;
      n=n/2;
      
  	}
	
   for (i=i-1;i>=0;i--)
    { 
      printf("%d" , a[i]);
  	}
 
}
