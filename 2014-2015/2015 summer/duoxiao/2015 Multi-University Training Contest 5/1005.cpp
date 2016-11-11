#include <iostream>
using namespace std;
double a[100]={0,1312,2372.3,520.2,899.5,800.6,1086.5,1402.3,1313.9,1681.0,2080.7,495.8,737.7,577.5,786.5,1011.8,999.6,1251.2,1520.6};
int main()
{
    a[35]=1139.9;
    a[36]=1350.8;
    a[53]=1008.4;
    a[54]=1170.4;
    a[86]=1037;
    int ta,tb;
    while(cin>>ta>>tb)
    {
        if(a[ta]>a[tb])
            cout<<"FIRST BIGGER"<<endl;
        else cout<<"SECOND BIGGER"<<endl;
    }
    return 0;
}
