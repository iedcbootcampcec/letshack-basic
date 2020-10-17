#include <stdio.h>
#include <string.h>
 
int main()
{
    char s[1000],c;  
    int i,count=0;
 
    printf("Enter  the string : ");
    gets(s);
    printf("Enter character ");
    c=getchar();
    
    for(i=0;s[i];i++)  
    {
    	if(s[i]==c)
    	{
          count++;
		}
 	}
     
	printf("character '%c' occurs %d times \n ",c,count);
 
}
