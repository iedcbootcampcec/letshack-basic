#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int global[0];

void *revs(void *args)
{
	int *number;
	number=args;
	
	int num,var,rev=0;
    num=number[0];
	while(num>0)
	{
	    var=num%10;
	    rev=(rev*10)+var;
	    num=num/10;
	}
	
	printf("reverse of the number is: %d",rev);
	

	return NULL;
}
 int main()
{
	printf("Enter the number: ");
	scanf("%d",&global[0]);



	pthread_t reverse;
	pthread_create(&reverse,NULL,revs,(void*)&global);
    pthread_exit(NULL);
	return 0;

}

