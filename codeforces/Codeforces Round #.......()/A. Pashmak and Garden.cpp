#include <iostream>
using namespace std;
int ans(int a)
{
    if(a>0) return a;
    else return -a;
}
int main()
{
    int x1,x2,y1,y2;
    cin>>x1>>y1>>x2>>y2;
    if(x1==x2)
    {
        cout<<x1+ans(y2-y1)<<" "<<y1<<" "<<x1+ans(y2-y1)<<" "<<y2;
    }
    else if(y1==y2)
    {
        cout<<x1<<" "<<y1+ans(x2-x1)<<" "<<x2<<" "<<y1+ans(x2-x1);
    }
    else if(ans(y1-y2)==ans(x1-x2))
    {
        cout<<x1<<" "<<y2<<" "<<x2<<" "<<y1;
    }
    else cout<<"-1";
    return 0;
}
