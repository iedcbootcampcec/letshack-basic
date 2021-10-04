//Producer Consumer

#include <stdio.h>
#include <stdlib.h>
int mutex=1, full=0, empty,x=0;
int main()
{
 int n;
 printf("Enter the Size: ");
 empty=n;
 void producer();
 void consumer();
 int wait(int);
 int signal(int);
 printf("\n1.Producer \n2.Consumer \n3. Exit");
 while(1)
{
  printf("\n Enter Your Choice");
  scanf("%d",&n);


 switch(n)
{
  case 1: if((mutex==1)&& (empty!=0))
            producer();
          else
            printf("Buffer Is Full");
          break;
  case 2: if((mutex==1)&&(full!=0))
            consumer();
          else
            printf("Buffer Is empty");
          break;
  case 3: exit(0);
          break;
}
}
return 0;
}

int wait(int s)
{
 return(--s);
}

int signal(int s) 
{
 return (++s);
}

void producer()
{
  mutex=wait(mutex);
  full=signal(full);
  empty=wait(empty);
  x++;
  printf("\n Producer Produces the Item %d",x);
  mutex=signal(mutex);
}

void consumer()
{
  mutex=wait(mutex);
  full=signal(full);
  empty=signal(empty);  
  printf("\n Consumer Consume item %d", x);
  x--;
  mutex=signal(mutex);
}
