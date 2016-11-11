#include <iostream>
using namespace std;
#include <math.h>
int n;
int a[5005];
int b[5005];
int judge(int a)
{
    for(int i=2;i<=sqrt(a);i++)
    {
        if(a%i==0) a=a/i;
    }
    return a;
}
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        cin>>a[i];
        b[i]=a[i];
    }
    int maxx=0;
    int t;
    for(int i=1;i<=n;i++)
    {
        if(judge(a[i])>maxx)
        {
            maxx=judge(a[i]);
            t=i;
        }
    }
    cout<<b[t];
    return 0;
}
