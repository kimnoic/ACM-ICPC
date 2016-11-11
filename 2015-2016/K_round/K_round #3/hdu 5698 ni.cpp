#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int MOD = 1e9+7;
LL inv(LL x,LL m){
    if(x==1) return x;
    return inv(m%x,m)*(m-m/x)%m;
}
//ÇóÄæÔª
int n,m;
int main(){
    while(cin>>n>>m){
    n-=2;
    m-=2;
    LL ans=1;
    for(int i=1;i<=(m+n);i++){
        ans*=(LL)i;
        ans%=MOD;
    }
    LL temp=1;
    for(int i=1;i<=n;i++){
        temp*=(LL)i;
        temp%=MOD;
    }
    temp=inv(temp,MOD);
    temp%=MOD;
    ans=ans*temp%MOD;
    temp=1;
    for(int i=1;i<=m;i++){
        temp*=(LL)i;
        temp%=MOD;
    }
    temp=inv(temp,MOD);
    temp%=MOD;
    ans=ans*temp%MOD;
    cout<<ans<<endl;}
    return 0;
}
