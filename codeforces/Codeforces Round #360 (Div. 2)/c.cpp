#include <bits/stdc++.h>
using namespace std;
const int maxn = 200100;
vector<int>mp[maxn];
int a[maxn],b[maxn];
int vis[maxn];
int n,m;
int cnt=0;
int f;
void dfs(int u,int k){
    //cout<<u<<" "<<k<<endl;
    vis[u]=k;
    int kk=k^1;
    for(int i=0;i<mp[u].size();i++){
        if(vis[mp[u][i]]==vis[u]){
            f=0;
            return ;
        }
        if(vis[mp[u][i]]==-1){
             dfs(mp[u][i],kk);
        }
    }
    //return true;
    //if(mp[u].size()==0) vis[u]=-1;
}
int main(){
    cin>>n>>m;
    memset(vis,-1,sizeof(vis));
    for(int i=1;i<=m;i++){
        int u,v;
        cin>>u>>v;
        mp[u].push_back(v);
        mp[v].push_back(u);
    }
    for(int i=1;i<=n;i++){
        if(vis[i]==-1){
            f=1;
            dfs(i,0);
            if(!f){
                cout<<-1;
                return 0;
            }
        }
    }
        int suma=0,sumb=0;
        for(int i=1;i<=n;i++){
            //cout<<i<<" "<<vis[i]<<endl;
            if(vis[i]==0){
                suma++;
                a[suma]=i;
            }
            else if(vis[i]==1){
                sumb++;
                b[sumb]=i;
            }
        }
        cout<<suma<<endl;
        for(int i=1;i<=suma;i++) cout<<a[i]<<" ";
        cout<<endl;
        cout<<sumb<<endl;
        for(int i=1;i<=sumb;i++) cout<<b[i]<<" ";
    return 0;
}
/*
6 5
1 2
2 3
3 4
3 5
4 5
*/
