#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>

void producer();
void consumer();
int wait(int);
int signal(int);

 int mutex =1,c,produced=0,empty,item=0;
void main(){

    printf("enter the space required");
    scanf("%d",&empty);
    printf("1.produce 2.consume 3.exit");
    while(1){

       printf("enter the choice");
       scanf("%d",&c);

       switch(c){
           case 1 :if(mutex == 1 && empty!=0)
                      producer();
                    else{
                        printf("buffer is full");
                    }
                      break;
            case 2 :if(mutex == 1 && produced!=0)
                      consumer();
                      else{
                        printf("buffer is empty");
                    }
                      break;
            case 3 :exit(0);
                    break;       
            default : printf("error");
                      break;
       }

    }

}

int signal(int p){
    return (++p);
}
int wait(int p){
    return (--p);
}

void producer(){
    mutex=wait(mutex);
    produced=signal(produced);
    empty=wait(empty);
    item++;
   printf("%d item created",item);

   mutex=signal(mutex);
}

void consumer(){
    mutex=wait(mutex);
    produced=wait(produced);
    empty=signal(empty); 
   printf("%d item created",item);
   item--;
   mutex=signal(mutex);
}
