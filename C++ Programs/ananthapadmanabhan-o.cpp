#include <iostream>  
using namespace std;  
int main()  
{  
 int i,f,n; 
 f=1;
 cout<<"Enter the number to find its factorial: ";    
 cin>>n;    
  for(i=1;i<=n;i++)
  {    
      f=f*i;    
  }    
  cout<<"The factorial of " <<n<<" is: "<<f<<endl;  
  return 0;  
}  
