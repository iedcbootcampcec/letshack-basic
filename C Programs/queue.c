#include<stdio.h>
#include<stdlib.h>

struct node
{
	int data;
	struct node* next;
};

struct node* ptr;
struct node* top=NULL;

void pop();
void push();
void display();

void main()
{
	int choice;
	while(1)
	{
		printf("\n1.push");
		printf("\n2.pop");
		printf("\n3.display");
		printf("\n4.exit");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1: push();display(); break;
			case 2: pop();display();break;
			case 3: display();break;
			case 4: return;
		}
	}
}

void push()
{
	ptr=(struct node*)malloc(sizeof(struct node));
	if(ptr==NULL)
	{
		printf("\n\tOVER FLOW");
		return;
	}
	int item;
	printf("Enter the element");
	scanf("%d",&item);
	ptr->data=item;
	ptr->next=top;
	top=ptr;
}

void pop()
{
	if(top==NULL)
	{
		printf("\n\tUnder flow");
		return;
	}

	ptr=top;
	printf("\nThe element popped is : ");
	printf("%d",top->data);
	top=top->next;
	free(ptr);
}

void display()
{
	if(top==NULL)
	{
		printf("Under flow");
		return;
	}
	ptr=top;
	printf("\nThe elements of stack are\n");
	while(ptr!=NULL)
	{
		printf("%d\t",ptr->data);
		ptr=ptr->next;
	}
}
