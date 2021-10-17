#include<stdio.h>
void main()
 { 
   int n,i,a[20],Product,sum =0;
   printf("Enter the number n : ");
   scanf ("%d" , &n);
   
   for (i=0;n>0;i++)
   { 
     a[i] = n%10;
     n = n/10;
	  
   }
   printf ("Each digits of n are \n");
   for (i=i-1;i>=0;i--)
    { 
      printf( " %d\n\n",a[i]);
      sum = sum + a[i];
	}
   
   
  
   printf ( "The total sum of each digits is %d" , sum);
   
}
 
