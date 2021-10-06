#include<stdio.h>
void main()
{ 
  int n,fact = 1, i;
  printf("Enter the digit n :");
  scanf ("%d" , &n);
  if (n<0)
   { 
    printf("Not applicable");
    
   }
   else{
   
  for (i=1;i<=n;i++)
    { 
      fact*=i;
      
	}
	printf("%d" , fact);
}
}
