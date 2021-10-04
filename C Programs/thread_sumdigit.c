#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int global[0];

void *sum(void *args)
{
	int *number;
	number=args;
	
	int num,var,rev=0;
    num=number[0];
	while(num>0)
	{
	    var=num%10;
	    rev=rev+var;
	    num=num/10;
	}
	
	printf("sum of the digits is: %d",rev);
	

	return NULL;
}
 int main()
{
	printf("Enter the number: ");
	scanf("%d",&global[0]);



	pthread_t sumdigit;
	pthread_create(&sumdigit,NULL,sum,(void*)&global);
    pthread_exit(NULL);
	return 0;

}

