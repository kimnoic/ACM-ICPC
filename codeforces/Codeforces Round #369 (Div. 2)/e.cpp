#include <bits/stdc++.h>
#define LL long long
const int mod = 1e6+3;
LL n,k;
LL lerang(LL p,LL n){
    LL ret=0;
    n/=p;
    while(n){
        ret+=n;
        n/=p;
    }
    return ret;
}
LL qpow(LL x,LL y){
    LL ret=1;
    while(y){
        if(y&1) ret=ret*x%mod;
        x=x*x%mod;
        y>>=1;
    }
    return ret;
}
int main(){
    std::cin>>n>>k;
    if(n<=60&&k>(1ll<<n)){
        printf("1 1\n");
        return 0;
    }
    LL left=lerang(2,k-1);
    LL s=qpow(2,n);
    LL ans=1;
    for(int i=1;i<=k-1;i++){
        ans=ans*(s-i)%mod;
        if(!ans) break;
    }
    LL ss=qpow(qpow(2,left),mod-2);
    ans=(ans*ss)%mod;
    LL ans2=qpow(s,(k-1));
    ans2=ans2*ss%mod;
    ans=(ans2-ans+mod)%mod;
    std::cout<<ans<<" "<<ans2;
    return 0;
}
