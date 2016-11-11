#include <bits/stdc++.h>
using namespace std;
const int maxn = 100100;
vector<int>mp[maxn];
int p[maxn],vis[maxn],cnt[maxn];
int n,m,a,b,k;
bool dfs(int u){
    if(p[u]<=k) k=p[u];
    else return false;
    for(int i=0;i<mp[u].size();i++){
        int kk=mp[u][i];
        return dfs(kk);
    }
    return true;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        mp[a].push_back(b);
        cnt[b]=1;
    }
    for(int i=1;i<=n;i++) cin>>p[i];
    for(int i=1;i<=n;i++){
        if(cnt[i]==0){
            k=n;
            if(dfs(i)==false){
                cout<<"-1";
                return 0;
            }
        }
    }
    return 0;
}
