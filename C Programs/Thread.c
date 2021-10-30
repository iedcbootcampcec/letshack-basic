#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int global[2];

void *sumOf(void *arg)
{
    int *arr;
    arr = arg;

    int n1,n2,sum;
    n1=arr[0];
    n2=arr[1];
    sum = n1+n2;

    printf("Sum , %d + %d = %d\n",n1,n2,sum);

    return NULL;
}

int main() 
{
    printf("Enter First number : ");
    scanf("%d",&global[0]);

    printf("Enter Second number : ");
    scanf("%d",&global[1]);

    pthread_t add; //unsigned integer value that stores the thread id of the thread created.
    pthread_create(&add,NULL,sumOf,global); //thread creation
    pthread_join(add,NULL);//waiting for the termination of a thread.
    printf("Thread ID: %lu ",add );//Printing thread ID

    return 0;
}
