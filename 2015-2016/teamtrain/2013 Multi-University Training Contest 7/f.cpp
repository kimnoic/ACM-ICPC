#include <bits/stdc++.h>
using namespace std;
const int maxn = 123;
vector<int>mp[maxn];
int vis[maxn];
int ans[maxn][maxn];
int n,m;
int main(){
    while(~scanf("%d%d",&n,&m)){
        for(int i=1;i<=n;i++) mp[i].clear();
        for(int i=1;i<=m;i++){
            mp[(i-1)%n+1].push_back(i);
            ans[i][1]=(i-1)%n+1;
        }
        for(int i=1;i<=n;i++){
            int t=m%n;
            for(int j=0;j<mp[i].size();j++){
                t=t%n+1;
                if(t==i) t=t%n+1;
                ans[mp[i][j]][2]=t;
            }
        }
        for(int i=1;i<=m;i++){
            memset(vis,0,sizeof(vis));
            vis[ans[i][1]]=1;
            vis[ans[i][2]]=1;
            int k=3;
            for(int j=1;j<=n;j++){
                if(!vis[j]){
                    ans[i][k]=j;
                    k++;
                }
            }
        }
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(j!=n) cout<<ans[i][j]<<" ";
                else cout<<ans[i][j]<<endl;
            }
        }
    }
    return 0;
}
