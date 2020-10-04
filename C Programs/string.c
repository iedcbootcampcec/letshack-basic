/*
* C Program to read and print string using scanf and printf
*/
#include <stdio.h>
#include <conio.h>

int main(){
    char inputString[100];
    printf("Enter a string\n");
    /* Read string from user using scanf and 
    store it in inputString char array */
    scanf("%s", inputString);
    /* Print string stored in inputString using printf */
    printf("%s\n", inputString);
    
    getch();
    return 0;
}
