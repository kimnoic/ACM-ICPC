#include <bits/stdc++.h>
using namespace std;
const int maxn = 23;
int cnt[233];
int vis[maxn],a[maxn],ans,b[maxn],n,k,l,now;
int viss[233];
void dfs(int x,int flag){
    if(x==k-1){
        if(!flag&&!cnt[now^l]) return ;
    }
    if(x==k){
        if(!flag) return ;
        for(int i=0;i<x;i++){
            int t=0;
            b[i+k]=b[i];
            for(int j=i;j<i+k;j++){
                t^=b[j];
                viss[t]=1;
            }
        }
        int p=l;
        while(viss[p]) p++;
        ans=max(ans,p-1);
        for(int i=0;i<x;i++){
            int t=0;
            for(int j=i;j<i+k;j++){
                t^=b[j];
                viss[t]=0;
            }
        }
        return ;
    }
    for(int i=0;i<n;i++){
        if(!vis[i]){
            now^=a[i];
            vis[i]=1;
            b[x]=a[i];
            cnt[a[i]]--;
            dfs(x+1,flag | (now==l));
            now^=a[i];
            vis[i]=0;
            cnt[a[i]]++;
        }
    }
}
int main(){
    while(scanf("%d%d%d",&n,&k,&l)==3){
        memset(vis,0,sizeof(vis));
        memset(cnt,0,sizeof(cnt));
        memset(viss,0,sizeof(viss));
        ans=0,now=0;
        for(int i=0;i<n;i++){
            scanf("%d",&a[i]);
            cnt[a[i]]++;
        }
        dfs(0,0);
        cout<<ans<<endl;
    }
    return 0;
}
