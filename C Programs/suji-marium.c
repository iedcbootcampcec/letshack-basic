#include <stdio.h>

int main()
{
  int a[5][5];
  int i,j,row,col,s;
    
    printf("Enter number of elements in the row:");
    scanf("%d",&row);
    
    printf("Enter number of elements in the column:");
    scanf("%d",&col);
   
    if(row == col)
     {
       for(i=0;i<row;i++)
       {
          printf("Enter elements in row %d:\n",i+1);
          for(j=0;j<col;j++)
               scanf("%d",&a[i][j]);
       }
   
       printf("The matrix is:");
       
       for(i=0;i<row;i++)
       {
          printf("\n");
          for(j=0;j<col;j++)
               printf("%d \t",a[i][j]);
       }  
    
       for(i=0;i<row;i++)
       { 
          for(j=0;j<col;j++)
             {
                 if(i==j)
                     s=s+a[i][j];
             }
       }
       printf("\nSum of diagonal elements in the matrix is %d",s);
     }
    else
       printf("Number of rows is not equal to number of columns");
    
    
}
