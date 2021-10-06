//Implementation Of system Calls 

#include <stdio.h>
#include <unistd.h>
void main()
{
int limit;
printf("Enter The Limit: ");
scanf("%d",&limit);
pid_t pid;
pid=fork();
if(pid==0)
{
 printf("********\n");
 printf("Child Process \n");
 printf("Even No.s Upto Limit %d : \n", limit);
 for(int i=0;i<=limit;i++)
 {
   if(i%2==0)
    printf("%d",i);
 }
 printf("\n");
 printf("Process ID of Child Process: %d \n", getpid());
}
else
{
 printf("********\n");
 printf("Parent Process \n");
 printf("********\n");
 printf("Odd No.s upto Limit %d : \n", limit);
 for(int i=0;i<=limit; i++)
 {
   if(i%2!=0)
    printf("%d",i);
 }
 printf("\n");
 printf("Process ID OF Parent Process %d", getpid());
}

}
