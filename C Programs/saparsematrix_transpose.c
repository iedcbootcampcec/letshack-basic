#include <stdio.h>
# define MAX_TERMS 100
int count=1;
typedef struct
{
    int row; 
    int column;
    int value;
}term;
term t[MAX_TERMS];


void normal_tuple(int A[10][10], int R,int C)
{
    int i,j;
    for(i=0;i<R;i++)
    {
        for(j=0;j<C;j++)
        {
            if(A[i][j]!=0)
                {
                t[count].row=i;
                t[count].column=j;
                t[count].value=A[i][j];
                count++;
                }
                
        }
    }
    t[0].row=R;
    t[0].column=C;
    t[0].value=count-1;
    
    printf("\nthe matrix in tuple form\n");
    for(i=0;i<count;i++)
        
        {
            printf("\n%d\t%d\t%d",t[i].row,t[i].column,t[i].value);
        }
} 
int main(){
    int a[10][10],r,c,flag;
    term s[100];
    printf("enter  no. of rows in matrix");
    scanf("%d",&r);
    printf("enter no .of columns in matrix");
    scanf("%d",&c);
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("\nEnter the element [%d][%d]:",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nthe matrix is:");
    for(int i=0;i<r;i++)
    {
        for(int j=0;j<c;j++)
        {
            printf("%d\t",a[i][j]);
            
        }
        printf("\n\n");
    }
    normal_tuple(a,r,c);
    for(int i=0;i<count;i++)
    {
        s[i].row=t[i].column;
        s[i].column=t[i].row;
        s[i].value=t[i].value;
        
    }
    printf("\ntranspose of entered matrix in normal form:");
    for(int i=0;i<c;i++)
    {
        for(int j=0;j<r;j++)
        {
            for(int k=1;k<count;k++)
            {
                flag=0;
                if((s[k].row==i)&&(s[k].column==j))
                {
                    printf("%d\t",s[k].value);
                    flag=1;
                    break;
                }
               
                
            }
            if(flag==0)
            {
                printf("0\t");
            }
        }
        printf("\n");
    }
    printf("\nTranspose of matrix in tuple form\n");
    for(int i=0;i<count;i++)
    {
        printf("\n%d\t%d\t%d",s[i].row,s[i].column,s[i].value);
    }
}
