#include<bits/stdc++.h>
using namespace std;
#define Max 100100
int g[Max];
int m,n,ans;
int main()
{
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>m;
        g[m]=g[m-1]+1;
        ans=max(ans,g[m]);
    }
    cout<<n-ans<<endl;
    return 0;
}
