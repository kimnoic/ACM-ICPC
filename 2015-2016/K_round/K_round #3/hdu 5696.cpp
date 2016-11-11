#include <bits/stdc++.h>
using namespace std;
const int N = 1e5+10;
int a[N];
long long ans[N];
void dfs(int l,int r){
    if(l>r) return ;
    if(l==r) ans[1]=max(ans[1],(long long)a[l]*a[l]);
    int p1=l,p2=l;
    for(int i=l;i<=r;i++){
        if(a[i]<a[p1]) p1=i;
        if(a[i]>a[p2]) p2=i;
    }
    ans[r-l+1]=max(ans[r-l+1],(long long)a[p1]*a[p2]);
    dfs(l,p1-1);
    dfs(p1+1,r);
}
int n;
int main(){
    while(~scanf("%d",&n)){
        memset(ans,0,sizeof(ans));
        for(int i=1;i<=n;i++){
            scanf("%d",&a[i]);
        }
        dfs(1,n);
        for(int i=n-1;i>0;i--)
            ans[i]=max(ans[i],ans[i+1]);
        for(int i=1;i<=n;i++) printf("%lld\n",ans[i]);
    }
    return 0;
}
