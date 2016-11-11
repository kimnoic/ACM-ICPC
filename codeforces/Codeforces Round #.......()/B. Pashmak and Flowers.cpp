#include <iostream>
using namespace std;
int minn;
int maxx;
int t;
int ans1=0,ans2=0;
int main()
{
    int n;
    cin>>n;
    cin>>t;
    maxx=t;
    long long ans1=1;
    minn=t;
    long long ans2=1;
    for(int i=2;i<=n;i++)
    {
        cin>>t;
        if(t==maxx)
        {
            ans1++;
        }
        if(t>maxx)
        {
            ans1=1;
            maxx=t;
        }
        if(t==minn)
        {
            ans2++;
        }
        if(t<minn)
        {
            minn=t;
            ans2=1;
        }
    }
    if(maxx-minn==0) cout<<"0 "<<ans2*(ans2-1)/2;
    else
    cout<<maxx-minn<<" "<<ans2*ans1;
    return 0;
}
