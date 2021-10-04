#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int global[0];

void *fib(void *args)
{
	int *number;
	number=args;
	
	int num,f=0,s=1,t;
    num=number[0];

    printf("fibonacci series:");
    printf("%d\t",f);
	printf("%d\t",s);
    for(int i=2;i<num;i++)
	{

		t=f+s;
		printf("%d\t",t);
		f=s;
		s=t;

	}
	return NULL;
}
 int main()
{
	printf("Enter the number: ");
	scanf("%d",&global[0]);



	pthread_t fibonacci;
	pthread_create(&fibonacci,NULL,fib,(void*)&global);
    pthread_exit(NULL);
	return 0;

}