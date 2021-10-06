/*
 
   C program to create two process,one parent process must bring odd numbers up to limit n.At the same time child process must bring even numbers upto n.Also print the process ID

 */


#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>

int main()

{
  int limit,i;
 
  printf("Enter the limit up to n :-\n");
  scanf("%d",&limit);
 
  pid_t pid;  //pid_t data type representing process ID
  pid = fork();  //fork() system call creates a child process.
 
  if(pid==0)  //child process
  {  
      printf("\n__CHILD PROCESS__\n");
      printf("Even numbers upto limit %d :-\n",limit);
      for ( i = 0; i <= limit; i++)
       {
          if(i%2==0)
          {  
            printf("%d\n",i);
          }
       }
      printf("Child process ID is : %d\n",getpid());
  }
  else   //parent process
  {
      printf("\n__PARENT PROCESS__\n");
      printf("Odd numbers upto limit %d :-\n",limit);
      for (int i = 0; i <= limit; i++)
       {
          if(i%2!=0)
          {    
              printf("%d\n",i);
          }
       }  
      printf("Parent Process ID is : %d\n", getpid() );
  }
 
} 