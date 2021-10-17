#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;
int main()
{
    char dd[10],mm[10],yy[10],dob[30];
    int d,m,y;
    cout<<"Enter day,month and year in your Date of Birth:  ";
    cin>>d>>m>>y;
    itoa(d,dd,10);
    itoa(m,mm,10);
    itoa(y,yy,10);
    strcpy(dob,dd);
    strcat(dob,"-");
    strcat(dob,mm);
    strcat(dob,"-");
    strcat(dob,yy);
    cout<<"Your Date of Birth is "<<dob;
    return 0;
}
