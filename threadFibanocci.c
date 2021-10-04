#include<stdio.h>
#include<stdlib.h>
#include<pthread.h>


int a[0];

void *fibonocci(void *arg){
    int *ar ;
    ar=arg;
    int limit =ar[0],i;
    int first=0,second=1,third;
    printf("fibonnaci series is as follows: \n");
    for(i=0;i<limit;i++){
      printf("%d",first);
      third=first+second;
      first=second;
      second=third;
      printf("\n");
    }
}

void main(){
    printf("enter the limit \n");
    scanf("%d",&a[0]);

    pthread_t f;
    pthread_create(&f,NULL,fibonocci,&a);
    pthread_join(f,NULL);
}
