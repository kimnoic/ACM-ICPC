#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define Max 500005

ll a[Max],d[Max],dp[Max];
int last[Max];
int main() {
    int n, q;
    cin>>n>>q;
    for(int i=1;i<=n;i++) cin>>a[i];

    for(int i=1;i<n;i++) d[i]=abs(a[i+1]-a[i]);
    d[0]=INT_MAX;

    for(int i=1;i<n;i++){
        int t=i-1;
        while(d[t]<d[i])
            t=last[t];
        last[i]=t;
    }

    while(q--){
        memset(dp,0,sizeof(dp));
        ll ans=0;
        int l,r;
        cin>>l>>r;
        r--;
        if(l>r){
            cout<<0;
            continue;
        }

        for(int i=l;i<=r;i++){
            int prev = last[i]>=l?last[i]:l-1;
            dp[i]=dp[prev]+(i-prev)*d[i];
            ans+=dp[i];
        }
        cout << ans << endl;
    }
    return 0;
}
