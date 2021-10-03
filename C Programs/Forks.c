#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void main(){
    int i,limit,a[1000];

    printf("enter the limit of no to be checked");
    scanf("%d",&limit);
    
    
    for(i=0;i<limit;i++){
      printf("enter the %d no",i+1);
      scanf("%d",&a[i]);
    }

    pid_t f;
    f=fork();

    if(f>0){
        printf("odd nos are as follow \n");
        for(i=0;i<limit;i++){
            if(a[i] % 2 !=0){
               printf("%d",a[i]);
            }
        }
        printf("parent id %d",getpid());
    }
    else{
        printf("\n even nos are as follow \n");
        for(i=0;i<limit;i++){
            if(a[i] % 2 ==0){
               printf("%d",a[i]);
            }
        }
        printf("child id %d",getpid());
    }

}
