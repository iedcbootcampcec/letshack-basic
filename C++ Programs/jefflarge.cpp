#include <iostream>
using namespace std;
int main() {
   int a = 5 ,b = 1 ,c = 9;
   if(a>b) {
      if(a>c)
      cout<<a<<" is largest number";
      else
      cout<<c<<" is largest number";
   }else {
      if(b>c)
      cout<<b<<" is largest number";
      else
      cout<<c<<" is largest number";
   }
   return 0;
