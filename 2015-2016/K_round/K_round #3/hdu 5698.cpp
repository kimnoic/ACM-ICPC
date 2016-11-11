#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int MOD = 1e9+7;
const int maxn = 1e6+10;
LL fac[maxn];
int n,m;
LL qpow(LL a,LL b){
    LL ans=1;a%=MOD;
    for(LL i=b;i;i>>=1,a=a*a%MOD){
        if(i&1) ans=ans*a%MOD;
    }
    return ans;
}
LL C(LL n,LL m){
    if(m>n || m<0) return 0;
    LL s1=fac[n],s2=fac[n-m]*fac[m]%MOD;
    return s1*qpow(s2,MOD-2)%MOD;
}
int main(){
    fac[0]=1;
    for(int i=1;i<maxn;i++)
        fac[i]=fac[i-1]*i%MOD;
    while(cin>>n>>m)
        printf("%lld\n",C(n+m-4,n-2));
    return 0;
}
