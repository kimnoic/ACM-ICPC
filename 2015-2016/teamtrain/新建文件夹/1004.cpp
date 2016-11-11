#include <bits/stdc++.h>
#define LL long long
LL quickpowmod(LL x,LL y,LL mo){
    LL ret=1;
    while(y){
        if(y&1)
            ret=ret*x%mo;
        x=x*x%mo;
        y>>=1;
    }
    return ret;
}
int main(){
    long long f=0,cnt=0;;
    long long n,y,x,mod;
    std::cin>>n>>y>>x>>mod;
    n=n*y;//%mod;
    long a=0,b=1;
    while(cnt<=n){
        f+=a*a;
        f%=mod;
        long long temp=b;
        b=a+2*b;
        a=temp;
        cnt++;
    }
    n=0;
    long long res=1;
    while(n<=f){
        res*=x;
        res%=mod;
        n++;
    }
    std::cout<<res;
    return 0;
}
/* 2010 2014 3030303 333*/
