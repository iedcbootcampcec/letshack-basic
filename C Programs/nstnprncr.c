#include<stdio.h>


long factorial(int);
long find_npr(int, int);
long find_ncr(int, int);

int main()
{
    printf("\n\n\t\tStudytonight - Best place to learn\n\n\n");

    int n, r;
    long npr, ncr;

    printf("Enter the value of n and r respectively: \n\n");
    scanf("%d%d", &n, &r);

    
    npr = find_npr(n, r);
    ncr = find_ncr(n, r);

    printf("\n\n\n\t\t%dC%d = %ld\n", n, r, ncr);
    printf("\n\n\t\t%dP%d = %ld\n", n, r, npr);

    printf("\n\n\t\t\tCoding is Fun !\n\n\n");
    return 0;
}


long find_ncr(int a, int b)
{
    return (factorial(a)/(factorial(b)*factorial(a-b)));
}


long find_npr(int a, int b)
{
    return (factorial(a)/factorial(a-b));
}


long factorial(int c)
{
    if(c == 1 || c == 0)
        return 1;
    else
        return c*factorial(c-1);
}
