//Implementation Of threads

#include <stdio.h>
#include <unistd.h>
#include <pthread.h>
int global[2];
void * sumof(void*arg)
{
  int *arr;
  arr=arg;
  int n1,n2,sum;
  n1=arr[0];
  n2=arr[1];
  sum=n1+n2;
  printf("Sum, %d+%d=%d \n", n1,n2,sum);
  return NULL;
}

int main()
{
  printf("Enter 1st Number: ");
  scanf("%d", &global[0]);
  printf("Enter 2nd Number: ");
  scanf("%d", &global[1]);
  pthread_t add;
  pthread_create (&add,NULL, sumof,global);
  pthread_join(add,NULL);
  printf("Thread ID :%lu \n",add);
  pthread_exit(NULL);
  return 0;
}
