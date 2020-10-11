#include <stdio.h>
#include <conio.h>
void main()
{
	int n1,n2,n3;
	float avg;
	clrscr();
	printf("\nENTER THREE NUMBERS: " );
	scanf("%d %d %d",&n1,&n2,&n3);
	avg=(n1+n2+n3)/3;
	printf("\nAVERAGE: %0.2f",avg);
	getch();
}
