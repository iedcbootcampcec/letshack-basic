#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int global_1[2],global_2[2];

void *sumOf(void *arg)
{
    int *arr;
    arr = arg;

    int n1,n2,sum;
    n1=arr[0];
    n2=arr[1];
    sum = n1+n2;

    printf("Sum => %d + %d = %d\n",n1,n2,sum);
    
    printf("End of thread\n");


    return NULL;
}

int main() 
{
    
    printf("Enter First number for Thread I : ");
    scanf("%d",&global_1[0]);

    printf("Enter Second number for Thread I: ");
    scanf("%d",&global_1[1]);

    printf("Enter First number for Thread II : ");
    scanf("%d",&global_2[0]);

    printf("Enter Second number for Thread II: ");
    scanf("%d",&global_2[1]);

    pthread_t add_t1,add_t2;
    pthread_create(&add_t1,NULL,sumOf,global_1);
    pthread_create(&add_t2,NULL,sumOf,global_2); 
    pthread_join(add_t1,NULL);
    pthread_join(add_t2,NULL);
    printf("Thread ID of Thread I: %lu \n",add_t1 );
    printf("Thread ID of Thread II: %lu ",add_t2 );

    return 0;
}
