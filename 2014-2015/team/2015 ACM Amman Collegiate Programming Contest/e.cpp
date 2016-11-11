#include <bits/stdc++.h>
using namespace std;
int n;
int s[233];
int T;
int main()
{
    cin>>T;
    while(T--)
    {
        cin>>n;
        int maxx=0;
        for(int i=1;i<=n;i++)
        {
            cin>>s[i];
            maxx=max(maxx,s[i]);
        }
        int c=100-maxx;
        int res=0;
        for(int i=1;i<=n;i++)
        {
            s[i]+=c;
            if(s[i]>=50) res++;
        }
        cout<<res<<endl;
    }
    return 0;
}
