#include<stdio.h>
#include<stdlib.h>
int *arr,n;
void read()
{
	int i;
	printf("Enter %d elements:\n",n);
	for(i=0;i<n;i++)
	{
		printf("Enter element %d: ",i+1);
		scanf("%d",(arr+i));
	}
}
void display()
{
	int i;
	printf("Array elements are:");
	for(i=0;i<n;i++)
	{
		printf("%d",*(arr+i));
		printf("\n");
	}
}
void main()
{
	printf("Enter total number of elements: ");
	scanf("%d",&n);
	arr=(int*)malloc(n*sizeof(int));
	if(arr==NULL)
	{
		printf("Memory allocation not possible \n");
	}
	read();
	display();
	free(arr);
}
