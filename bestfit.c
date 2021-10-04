#include<stdio.h>
int find_min(int a[],int n)
{
    int min=0,i;
    for(i=0;i<n;i++)
    {
        if(a[i]<a[min])
        {
            min=i;
        }
    }
    return min;
}
void main()
{

    int process_size[10],block_size[10],temp[10]={0},alloc[10]={0},temp2[10]={0};
    int i,j,bno,pno,count=0,k,flag=0,l;
    printf("enter the number of blocks:\n");
    scanf("%d",&bno);
    printf("enter the number of processes:\n");
    scanf("%d",&pno);
    for(i=0;i<bno;i++)
    {
        printf("\nenter block%d size:",i);
        scanf("%d",&block_size[i]);
    }
     for(i=0;i<pno;i++)
    {
        printf("\nenter process%d size:",i);
        scanf("%d",&process_size[i]);
    }
    for(i=0;i<pno;i++)
    {
        count=0;
        flag=0;
        for(j=0;j<bno;j++)
        {
            if(process_size[i]<=block_size[j])
            {
                temp[count]=block_size[j];
                temp2[count]=j;
                count++;
                flag++;
            }
        }
            if(flag==0)
            {
                alloc[i]=-1;
            }
           else
           {
                k= find_min(temp,count);
                alloc[i]=temp2[k];
                l=temp2[k];
                block_size[l]=block_size[l]-process_size[i];

           }

        }
        printf("block no:-1 indicates no block has been allocated!\n");
        printf("Process\t\t\tProcess size\t\t\tAllocated block no:\n");
        for(i=0;i<pno;i++)
        {
            printf("%d\t\t\t%d\t\t\t%d",i,process_size[i],alloc[i]);
            printf("\n");
        }
    }


