#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

const int maxn=202501;
#define mod 1000000007
#define eps 1e-9
const int inf=0x3f3f3f3f;
const ll infll = 0x3f3f3f3f3f3f3f3fLL;
int n,k;
ll a[maxn];
ll sum=0;
int main()
{
    cin>>n>>k;
    ll minn=inf;
    for(int i=1;i<=n;i++)
        cin>>a[i],minn=min(minn,a[i]);
    for(int i=1;i<k;i++)
        sum+=a[i];
    ll ans=0;
    for(int i=k;i<=n;i++)
    {
        sum+=a[i]-a[i-k];
        if(sum>=0)
        {
            ans+=(sum+1);
            ll tmp=sum+1;
            int now=i;
            while(tmp)
            {
                ll kiss=min(tmp,a[now]-minn);
                a[now]-=kiss;
                tmp-=kiss;
                now--;
            }
            sum=-1;
        }
    }
    cout<<ans<<endl;
    for(int i=1;i<=n;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
