#include<stdio.h>
void main ()
{ float a , b ;
  float sum = 0 , mul = 0;
  float div = 0 , sub = 0;
  printf ("Enter the number a : ");
  scanf ("%f",&a);
  printf ("Enter the number b : ");
  scanf ("%f" , &b);
  sum = a + b;
  mul = a*b;
  div = a/b;
  sub = a - b;
  printf ("Sum of a and b = %.2f\n",sum);
  printf ("Difference of a and b = %.2f\n",sub);
  printf ("Product of a and b = %.2f\n" ,mul);
  printf ("Quotient obtained on dividing a and b = %.2f" ,div);
}
