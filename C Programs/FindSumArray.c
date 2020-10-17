#include<stdio.h>
int main()
{
	int a[10],b[10],sum[10],i,n;
	printf("how many numbers you want to enter");
	scanf("%d",&n);
	printf("enter the first array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&a[i]);
	}
	printf("enter the second array\n");
	for(i=0;i<n;i++)
	{
		scanf("%d",&b[i]);
	}
	for(i=0;i<n;i++)
	{
		sum[i]=a[i]+b[i];
	}
	printf("the sum of two array is\n");
	for(i=0;i<n;i++)
	{
		printf("%d\n",sum[i]);
	}
}
