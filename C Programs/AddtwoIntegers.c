#include <stdio.h>
int main() {    

    int a,b,sum;
    
    printf("Enter two integers: ");
    // inputting the numbers to be added
    scanf("%d %d", &a, &b);

    // calculating sum
    sum=a+b;      
    
    //printing the results
    printf("%d + %d = %d",a,b,sum);
    return 0;
}
