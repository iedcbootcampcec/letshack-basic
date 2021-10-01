# include<stdio.h>
# include<stdlib.h>
void read(int N,int *ptr);
void display(int N,int *ptr);
int main()
{
    int *ptr;
    int n;
    printf("Enter the size of Array:");
    scanf("%d",&n);
    ptr=(int*)malloc(n*sizeof(int));
    if(ptr==NULL)
    {
        printf("Memory not allocated");
        exit(0);
    }
    else
    {
        read(n,ptr);
        display(n,ptr);
        free(ptr);
    }
}    
    void read(int N,int *ptr)
    {
        int i;
        printf("Enter the elements:");
        for(i=0;i<N;i++)
        {
            scanf("%d",ptr[i]);
        }
    }
    void display(int N,int*ptr)
    {
        int i;
        printf("Displaying Elements:");
        for ( i = 0; i < N; i++)
        {
            printf("%d ",ptr[i]);
        }
        
    }
    
    
