#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<math.h>

int stack[100];
int top;
void push(int n)
{
    top=top+1;
    stack[top]=n;
}

int pop()
{   
    int value;
    value=stack[top];
    top=top-1;
    return value;
}

void evalpost(char a[])
{ 
    int i,k;char ch,b,c;
    for(i=0;a[i]!='#';i++)
    {
        ch=a[i];
        if(isdigit(ch))
            push(ch-'0');
        else
        {
            b=pop();
            c=pop();
            switch(ch)
            {
                case '+':   k=c+b;
                            push(k);
                            break;
                            
                case '-':   k=c-b;
                            push(k);
                            break;
                            
                case '*':
                            k=c*b;
                            push(k);
                            break;
                            
                case '/':
                            k=c/b;
                            push(k);
                            break;
                            
                case '^':
                            k=pow(c,b);
                            push(k);
                            break;
            }
       }
    }
    printf("\nResult: %d",pop());
}

void main()
{
    char a[50]; int len;
    printf("\nEnter A Postfix Expression:\t");
    scanf("%s",a);
    len=strlen(a);
    a[len]='#';
    evalpost(a);
    printf("\n");
}
