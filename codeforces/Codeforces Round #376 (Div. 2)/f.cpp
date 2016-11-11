#include <bits/stdc++.h>
#define ll long long
const int MAXN=200000+100;
int a[MAXN],pre[MAXN*2];
int main(){
    std::memset(pre,0,sizeof(pre));
    int n;
    scanf("%d",&n);
    for(int i=1;i<=n;i++) scanf("%d",&a[i]),pre[a[i]]++;
    for(int i=1;i<=MAXN*2;i++) pre[i]=pre[i-1]+pre[i];
    std::sort(a+1,a+n+1);
    int m=std::unique(a+1,a+n+1)-a-1;
    ll ans=0;
    for(int i=1;i<=m;i++){
        ll tmp=0;
        for(int j=2;(j-1)*a[i]<=a[m];j++){
            int p=(j-1)*a[i],q=j*a[i];
            tmp+=(ll)(pre[q-1]-pre[p-1])*a[i]*(j-1);
        }
        ans=std::max(ans,tmp);
    }
    printf("%I64d\n",ans);
    return 0;
}
