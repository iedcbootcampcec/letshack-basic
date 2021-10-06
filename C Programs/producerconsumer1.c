#include<stdio.h>
int full=0;
int empty=5;
int mutex=1;
int x=0;
int buffer[5];
int in=0;
int out=0;
void producer()
{
    --mutex;
    --empty;
    x++;
    buffer[in]=x;
    printf("\nproducer produced %d",buffer[in]);
    in=(in+1)%5;
    ++full;
    ++mutex;

}
void consumer()
{
    --mutex;
    --full;
    printf("\nconsumer consumed %d",buffer[out]);
    out=(out+1)%5;
    ++mutex;
    ++empty;
}
void main()
{
    int i,n;
    int option=0;
    printf("\n1 for producer""\n2 for consumer""\n3 for exit");
    while(option!=3)
    {
        printf("\nenter the choice");
        scanf("%d",&n);
        switch(n)
        {
        case 1:
            if(mutex==1 && empty!=0)
            {
                producer();
            }
            else{
                printf("\nfull");
            }
            break;
        case 2:
            if(mutex==1&&full!=0)
            {
                consumer();
            }
            else{
                printf("\nempty");
            }
            break;
        case 3:
            exit(1);

        }
    }

}
