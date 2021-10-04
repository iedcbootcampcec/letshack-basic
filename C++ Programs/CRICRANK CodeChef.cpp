#include <iostream>
using namespace std;

int main() {
	int t;
    cin>>t;
    while(t--)
    {
        int r1,w1,c1,r2,w2,c2,f=0,c=0,d=0;
        cin>>r1>>w1>>c1;
        cin>>r2>>w2>>c2;
        if(r1>r2)
        {
           f=1;
        }
        if(w1>w2)
        {
            c=1;
        }
        if(c1>c2)
        {
            d=1;
        }
        if((f+c+d)<=3 && (f+c+d)!=1 && (f+c+d)!=0 )
        {
            cout<<"A"<<"\n";
        }
        else
        {
            cout<<"B"<<"\n";
        }
    }
	return 0;
}
