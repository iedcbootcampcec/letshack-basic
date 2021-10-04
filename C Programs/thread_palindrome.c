#include <stdio.h>
#include <unistd.h>
#include <pthread.h>

int global[0];

void *pal(void *args)
{
	int *number;
	number=args;
	
	int num,var,rev=0,temp;
    num=number[0];
	temp=num;
	while(num>0)
	{
	    var=num%10;
	    rev=(rev*10)+var;
	    num=num/10;
	}
	if(temp==rev)
		printf("the number is palindrome");
	else
		printf("the number is not palindrome");

	return NULL;
}
 int main()
{
	printf("Enter the number: ");
	scanf("%d",&global[0]);



	pthread_t palindrome;
	pthread_create(&palindrome,NULL,pal,(void*)&global);
    pthread_exit(NULL);
	return 0;

}

