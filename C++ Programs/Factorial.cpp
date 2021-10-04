#include <iostream>
#include<conio.h>
using namespace std;

/*

//For n>16 will not work with this function.//

int fact(int n)
{
   if(n==0)
        return 1;
   return n*fact(n-1);
}
*/

//Using recursion in Factorial may cause stack overflow problem if the recursive call is large in number, so it needs change..

//----------------------------------------------------------------// CHANGED CODE//----------------------------------------------------------------//

unsigned long long int fact(unsigned long long int n)
{
    unsigned long long int fact = 1;
    unsigned long long int i=2;
    while (i<=n)
    {
        fact = fact * i;
        i++;
    }
    return fact;
//THIS PROGRAM CAN GIVE FACTORIAL OF UPTO 65 NUMBER. 
}

int main()
{
    unsigned int n;
    unsigned long long factorial = 1;

    cout << "Enter a positive integer: ";
    cin >> n;

//     for(int i = 1; i <=n; ++i)
//     {
//         factorial *= i;
//     }

    
    cout << "Factorial of " << n << " = " << fact(n);    
    return 0;
}
