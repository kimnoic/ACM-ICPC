#include <iostream>
using namespace std;
#define N 1000005
char a[N];
int main()
{
    int m,t,u,f,d;
    cin>>m>>t>>u>>f>>d;
    int ans=0;
    for(int i=1;i<=t;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<=t;i++)
    {
        if(a[i]=='u') m-=u+d;
        else if(a[i]='f') m-=f*2;
        else if(a[i]='d') m-=u+d;
        if(m<=0) break;
        ans++;
    }
    cout<<ans;
    return 0;
}
