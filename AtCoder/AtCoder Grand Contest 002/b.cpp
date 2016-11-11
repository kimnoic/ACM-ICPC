#include <bits/stdc++.h>
const int maxn=1e5+10;
int a[maxn],n,m;
bool vis[maxn];
int main(){
    std::cin>>n>>m;
    std::memset(vis,0,sizeof(vis));
    vis[1]=1;
    for(int i=1;i<=n;i++){
        a[i]=1;
    }
    int x,y;
    for(int i=1;i<=m;i++){
        std::cin>>x>>y;
        if(a[x]==1&&vis[x]){
            vis[x]=0;
            a[x]--;
            vis[y]=1;
            a[y]++;
        }
        else if(a[x]>=1&&vis[x]){
            a[x]--;
            a[y]++;
            vis[y]=1;
        }
        else {
            a[x]--;
            a[y]++;
        }
    }
    int sum=0;
    for(int i=1;i<=n;i++){
        if(vis[i]) sum++;
    }
    std::cout<<sum;
    return 0;
}
