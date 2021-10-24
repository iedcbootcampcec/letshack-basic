#include<stdio.h>
void main()
{ int n,i,a[10];
  printf("Enter the number n:");
  scanf("%d",&n);
  for ( i=0;n>0;i++)
    { 
      a[i] = n%8 ;
      n=n/8 ;
	}
   printf( 	"The octal number is :" ); 
  for (i=i-1;i>=0;i--)
    { 
      printf( "%d" ,a[i]);
	 } 
}
