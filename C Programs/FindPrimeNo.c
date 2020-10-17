#include<stdio.h>
int main()
{
	int a[50],n,i,j,pr=0,prime[50],t=0;
	printf("how many numbers you want to enter");
	scanf("%d",&n);
	printf("enter the numbers");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	for(i=0;i<n;i++)
	{
		pr=0;
		for(j=2;j<a[i];j++)
		{
			if(a[i]%j==0)
			{
				pr=1;
				break;
			}
		}
		if(pr==0)
		{
			prime[t]=a[i];
			t++;
		}
	}
	printf("prime numbers are\n");
	for(i=0;i<t;i++)
		printf("%d\n",prime[i]);
}
