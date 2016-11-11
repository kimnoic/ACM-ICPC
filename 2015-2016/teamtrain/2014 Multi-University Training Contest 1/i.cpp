#include <bits/stdc++.h>
using namespace std;
#define LL long long
const int MOD = 1e9+9;
const int maxn = 1e5+10;
int n,m;int a,b,x,mi,ma;
LL inv(LL x,LL m){
    if(x==1) return x;
    return inv(m%x,m)*(m-m/x)%m;
}
LL fac[maxn];
int main(){
    fac[0]=1;
    for(int i=1;i<maxn;i++)
        fac[i]=fac[i-1]*i%MOD;
    while(~scanf("%d%d",&n,&m)){
        mi=0;
        ma=0;
        for(int i=0; i<n; i++){
            scanf("%d",&x);
            if(mi-x>=0) a=mi-x;
            else if(ma-x>=0){
                if(mi%2==x%2)a=0;
                else a=1;
            }
            else a=x-ma;
            if(ma+x<=m)b=ma+x;
            else if(mi+x<=m){
                if((mi+x)%2==m%2)b=m;
                else b=m-1;
            }
            else b=m-(x-(m-mi));
            mi=a;
            ma=b;
//            cout<<mi<<" "<<ma<<endl;
        }
        long long sum=0;
//        cout<<mi<<" "<<ma<<endl;
        for(int i=mi;i<=ma;i+=2){
            sum+=((fac[m]*inv(fac[i],MOD)%MOD)*inv(fac[m-i],MOD))%MOD;
            sum%=MOD;
        }
        cout<<sum<<endl;
    }
    return 0;
}
