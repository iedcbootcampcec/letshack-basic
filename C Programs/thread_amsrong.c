#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int global[0];

void *arms(void *args)
{
	int *number;
	number=args;
	
	int num,var,rev=0,temp;
    num=number[0];
	temp=num;
	while(num>0)
	{
	    var=num%10;
	    rev=rev+(var*var*var);
	    num=num/10;
	}
	if(temp==rev)
		printf("the number is armstrong");
	else
		printf("the number is not armstrong");

	return NULL;
}
 int main()
{
	printf("Enter the number: ");
	scanf("%d",&global[0]);



	pthread_t armstrong;
	pthread_create(&armstrong,NULL,arms,(void*)&global);
    pthread_exit(NULL);
	return 0;

}

