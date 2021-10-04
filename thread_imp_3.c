//CProgram to create two thread and execute the addition of two numbers parallely in both threads.


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

    pthread_t add_t1,add_t2; //unsigned integer values that stores the thread id of the threads created.
    pthread_create(&add_t1,NULL,sumOf,global_1); //thread I creation
    pthread_create(&add_t2,NULL,sumOf,global_2); //thread II creation
    pthread_join(add_t1,NULL);//waiting for the termination of a thread I.
    pthread_join(add_t2,NULL);//waiting for the termination of a thread II.
    printf("Thread ID of Thread I: %lu \n",add_t1 );//Printing 1st thread ID
    printf("Thread ID of Thread II: %lu ",add_t2 );//Printing 1st thread ID

    return 0;
}
