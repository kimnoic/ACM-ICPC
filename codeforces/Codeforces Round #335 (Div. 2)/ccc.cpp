#include <bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    int p[n];
    int pos[n+5];
    for(int i=0;i<n;i++){
        cin>>p[i];
        pos[p[i]]=i;
    }
    int dp[n+1];
    dp[1]=1;
    for(int i=2;i<=n;i++){
        if(pos[i]>pos[i-1]){
            dp[i]=dp[i-1]+1;
        }
        else dp[i]=1;
    }
    int lis=0;
    for(int i=1;i<=n;i++){
        lis=max(dp[i],lis);
    }
    cout<<n-lis;
    return 0;
}
