#include<stdio.h>
   int fact(int);
   void main ()
      {
           int n, f ;
           printf(" Enter a number \n");
           scanf("%d", &n);
           
            f = fact(n);
            printf("\n The factorial of %d is %d is %d ", n,f );
}

int fact(int a)
{
    int i,s ;
    If (a==1)
        s=1;
     else 
         s = a*fact(a-1);
     return s ;
}
