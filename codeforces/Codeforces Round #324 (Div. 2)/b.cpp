#include <bits/stdc++.h>
using namespace std;
#define MOD 1000000007
long long modexp(int a,int b,int n){
    long long ret=1;
    long long tmp=a;
    while(b){
       if(b&0x1) ret=ret*tmp%n;
       tmp=tmp*tmp%n;
       b>>=1;
    }
    return ret;
}
int main(){
    int n;
    cin>>n;
    int res=(modexp(3,3*n,MOD)-modexp(7,n,MOD))%MOD;
    if(res<0) res+=MOD;
    cout<<res;
    return 0;
}
