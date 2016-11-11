#include <bits/stdc++.h>
const int maxn = 4e5+10;
int n,fa[maxn],sz[maxn],dw[maxn],up[maxn];
std::vector <int> edge[maxn];
void dfs_sz(int u,int p){
    sz[u]=1;
    fa[u]=p;
    for(auto v : edge[u]){
        if(v!=p){
            dfs_sz(v,u);
            sz[u]+=sz[v];
        }
    }
}
void dfs_dw(int u,int p){
    dw[u]=(sz[u]<=n/2 ? sz[u] : 0);
    for(auto v:edge[u]){
        if(v!=p){
            dfs_dw(v,u);
            dw[u]=std::max(dw[u],dw[v]);
        }
    }
}
void dfs_up(int u,int val,int p){
    up[u]=std::max((n-sz[u]<=n/2 ? n-sz[u] : 0),val);
    int mx0=0,mx1=0;
    for(auto v:edge[u]){
        if(v!=p){
            if(dw[v]>mx0){
                mx1=mx0;
                mx0=dw[v];
            }
            else if(dw[v]>mx1) mx1=dw[v];
        }
    }
    for(auto v:edge[u]){
        if(v!=p){
            dfs_up(v,std::max((dw[v]==mx0?mx1:mx0),up[u]),u);
        }
    }
}
void solve(){
    for(int i=1;i<=n;i++){
        int temp=1;
        for(auto &&v:edge[i]){
            if(v==fa[i]){
                if(n-sz[i]-up[i]>n/2){
                    temp=0;
                    break;
                }
            }
            else if(sz[v]-dw[v]>n/2){
                temp=0;
                break;
            }
        }
        std::cout<<temp<<" ";
    }
}
int main(){
    std::cin>>n;int u,v;
    for(int i=1;i<n;i++){
        std::cin>>u>>v;
        edge[u].push_back(v);
        edge[v].push_back(u);
    }
    //std::cout<<"asdf";
    dfs_sz(1,-1);

    dfs_dw(1,-1);
    dfs_up(1,0,-1);
//    for(int i=1;i<=n;i++) std::cout<<i<<" "<<up[i]<<" "<<dw[i]<<std::endl;
    solve();
    return 0;
}
