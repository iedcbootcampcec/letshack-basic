/*
   program to create a thread called add, which acess two integers from the user and print the sum.
   
*/
#include <stdio.h>
#include <pthread.h> //Include the header file " pthread.h ".
#include <unistd.h>

int global[2];  //// Global variable

void *sum_thread(void *arg)
{
    int n1,n2,sum;
    n1 = global[0];
    n2 = global[1];
    sum = n1+n2;

    printf("Sum = %d\n",sum);

    return NULL;
}
int main()
{
    printf("Enter the first integer:- ");
    scanf("%d",&global[0]);

    printf("Enter the second integer:- ");
    scanf("%d",&global[1]);

    pthread_t add_thread;  //thread decleration.Here " pthread_t " is the datatype.
    pthread_create(&add_thread, NULL, sum_thread, global);  //thread is created.
    pthread_join(add_thread,NULL);  // // Waiting for the created thread to terminate.
   
    return 0;
}
// to compile the program --->" gcc -o test prgrmName.c -pthread "
//  instead of ./a.out use --> "  ./test  "   