



Search Programiz
C++ Program to Check Whether a Number is Prime or Not
C++ Program to Check Whether a Number is Prime or Not
Example to check whether an integer (entered by the user) is a prime number or not using for loop and if...else statement.

To understand this example, you should have the knowledge of the following C++ programming topics:

C++ if, if...else and Nested if...else
C++ for Loop
C++ break and continue Statement
A positive integer which is only divisible by 1 and itself is known as prime number.

For example: 13 is a prime number because it is only divisible by 1 and 13 but, 15 is not prime number because it is divisible by 1, 3, 5 and 15.

Note: 0 and 1 are not prime numbers.

Example: Check Prime Number
#include <iostream>
using namespace std;

int main() {
    int i, n;
    bool isPrime = true;

    cout << "Enter a positive integer: ";
    cin >> n;

    // 0 and 1 are not prime numbers
    if (n == 0 || n == 1) {
        isPrime = false;
    }
    else {
        for (i = 2; i <= n / 2; ++i) {
            if (n % i == 0) {
                isPrime = false;
                break;
            }
        }
    }
    if (isPrime)
        cout << n << " is a prime number";
    else
        cout << n << " is not a prime number";

    return 0;
}



