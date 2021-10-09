/*Program to print transpose of a matrix*/
#include<stdio.h>
      void main()
      {
	int i,j,a,b;
	int n[10][10];
	int m[10][10];
	printf("Enter number of rows and columns of matrix\n");
	scanf("%d%d",&a,&b);
	printf("Enter matrix\n");
	for(i=0;i<a;i++)
	  {
	    for(j=0;j<b;j++)
	      {
		scanf("%d",&n[i][j]);
	       }
	  }
	for(i=0;i<b;i++)
	  {
	    for(j=0;j<a;j++)
	      {
		m[i][j]=n[j][i];
	       }
	   }
	printf("Transpose of given matrix\n");
	for(i=0;i<b;i++)
	  {
	    for(j=0;j<a;j++)
	      {
		printf("%d ",m[i][j]);
	       }
	    printf("\n");
	  }
        }
