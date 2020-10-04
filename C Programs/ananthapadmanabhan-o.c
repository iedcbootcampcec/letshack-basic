#include <stdio.h>
int main()
{
    int num_1,num_2;
    float result;
    char operation;   
    printf("--------Basic Calculator--------\n");
    printf("Enter a number: ");
    scanf("%d",&num_1);
    printf("Enter another number: ");
    scanf("%d",&num_2);
     
    printf("\nFor addition enter + \nFor subtraction enter -\nFor multiplication enter *\nFor division enter /\n");
  
    scanf(" %c",&operation);
     
    switch(operation)    
    {
        case '+':
            result=num_1+num_2;
            break;
             
        case '-':
            result=num_1-num_2;
            break;
         
        case '*':
            result=num_1*num_2;
            break;
             
        case '/':
            result=(float)num_1/(float)num_2;
            break;
             
        default:
            printf("Invalid operation.\n");
    }
 
    printf("The result is: %f\n", result);
    printf("\n--------Thank you--------");
    return 0;
}
