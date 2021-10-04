#include<stdio.h>
#include<conio.h>
//   Defining structure
struct poly 
{
	int coeff;
	int exp;
};
int main()
{
	int m,n,i,j,k=0,l=0,x,y;
	struct poly a[50],b[50],c[50];
	
//	Reading degree of first polynomial
	printf("Enter the degree of first polynomial\n");
	scanf("%d",&m);
	x=m;
	
//	Reading degree of second polynomial
	printf("Enter the degree of second polynomial\n");
	scanf("%d",&n);
	y=n;
	
//	Reading first polynomial
	for(i=0;i<=m;i++)
	{
		printf("Enter the coefficient of x^%d in first polynomial\n",x);
		scanf("%d",&a[i].coeff);
		a[i].exp=x;
		x--;
	}
	
//	Reading second polynomial
	for(j=0;j<=n;j++)
	{
		printf("Enter the coefficient of x^%d in second polynomial\n",y);
		scanf("%d",&b[j].coeff);
		b[j].exp=y;
		y--;
	}
	
//	Displaying first polynomial
	printf("First polynomial is: ");
	for(i=0;i<=m;i++)
	{
		printf("%dx^%d+",a[i].coeff,a[i].exp);
	}
	
//	Displaying second polynomial
	printf("\nSecond polynomial is: ");
	for(j=0;j<=n;j++)
	{
		printf("%dx^%d+",b[j].coeff,b[j].exp);
	}
	
//	ADDING POLYNOMIALS

//	Case:1 When polynomials have same degree
	if(m==n)
	{
		for(i=0;i<=m;i++)
		{
			c[i].coeff=a[i].coeff+b[i].coeff;
			c[i].exp=a[i].exp;
		}
	}
	
//		Case 2: When degree of first polynomial is greater
	else if(m>n)
	{

		for(i=0;i<=m;i++)
		{
//		If exponents are equal
			if(a[k].exp==b[l].exp)
			{
//				Adding corresponding coefficients
				c[i].coeff=a[k].coeff+b[l].coeff;
				c[i].exp=a[k].exp;
				k++;
				l++;
			}
//			If exponents are not equal
			else if(a[k].exp>b[l].exp)
			{
				c[i].coeff=a[k].coeff;
				c[i].exp=a[k].exp;
				k++;
			}

			
		}
	}
	
//	Case 2: When degree of second polynomial is greater
	else if(n>m)
	{

		for(i=0;i<=n;i++)
		{
//		If exponents are equal
			if(a[k].exp==b[l].exp)
			{
//				Adding corresponding coefficients
				c[i].coeff=a[k].coeff+b[l].coeff;
				c[i].exp=a[k].exp;
				k++;
				l++;
				
			}
//			If exponents are not equal
			else if(a[k].exp<b[l].exp)
			{
				c[i].coeff=b[l].coeff;
				c[i].exp=b[l].exp;
				l++;
			}
		}
	}
	
//	Displaying the resultant polynomial after addition
	printf("\nResultant polynomial is: ");
	if(m==n || m<n)
	{
	
	   for(i=0;i<=n;i++)
		{
		printf("%dx^%d+",c[i].coeff,c[i].exp);
		}
    }
    else if(m>n)
    {
    	for(i=0;i<=m;i++)
		{
		printf("%dx^%d+",c[i].coeff,c[i].exp);
		}
	}
}
