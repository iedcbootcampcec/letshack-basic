#include <math.h>
#include <stdio.h>
double Series(int n)
{
int i;
double sums = 0.0, ser;
for (i = 1; i <= n; ++i) {
ser = 1 / pow(i, i);
sums += ser;
} 
return sums;
}
int main()
{
int n ;
printf("Enter the limit ");
scanf("%d",&n);
double res = Series(n);
printf("\n sum of the series is %f", res);
return 0;
}
