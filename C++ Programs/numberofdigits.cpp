#include <iostream>
#include <math.h>
using namespace std;

int countDigit(int n);
int main()
{
	int n;
	cin >> n;
	cout << "Number of digits : " << countDigit(n) << endl;
	return 0;
}

// LOG METHOD
int countDigit(int n)
{
	return floor(log10(n) + 1); //direct method but it requires math.h
}

// Iterative Method

// int countDigit(int n) {
//     int count=0;
//     int temp=n;
//     while(temp!=0){
//         temp=temp/10;
//         count++;
//     }
//     return count;
// }
