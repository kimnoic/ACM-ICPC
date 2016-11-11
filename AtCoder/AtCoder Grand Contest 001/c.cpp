#include <bits/stdc++.h>
using namespace std;
vector<int>tr[2333];
vector<int>tree[2333];
int n,k;
int vis[2333];/*
void dfs(int u){
    for(int i=0;i<tr[u].size();i++){
        int temp=tr[u][i];
        if(!vis[temp]){
            tree[u].push_back(temp);
            dfs(temp);
        }
    }
}*/
int sum,maxx;
void dfs(int u,int cnt){
    vis[u]=1;
    if(k%2==0){
        if(cnt>k/2) return ;
        else {
            for(int i=0;i<tr[u].size();i++){
                int temp=tr[u][i];
                if(!vis[temp]){
                    if(cnt<=k/2){
                        sum+=1;
                        dfs(temp,cnt+1);
                    }
                }
            }
        }
    }
    else {
        if(cnt>k/2+1) return ;
        else {
            for(int i=0;i<tr[u].size();i++){
                int temp=tr[u][i];
                if(!vis[temp]){
                    if(cnt==k/2+1){
                        if(cnt!=1){
                            int len=tr[u].size()-1;
                            maxx=max(maxx,len);
                        }
                        else {
                            maxx=max(maxx,1);
                        }
                    }
                    else {
                        sum++;
                        dfs(temp,cnt+1);
                    }
                }
            }
        }
    }
}
int main(){
    cin>>n>>k;
    for(int i=1;i<n;i++){
        int u,v;
        cin>>u>>v;
        tr[u].push_back(v);
        tr[v].push_back(u);
    }
    if(k==1){
        cout<<2;
        return 0;
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        sum=1;
        memset(vis,0,sizeof(vis));
        maxx=0;
        dfs(i,1);
        //cout<<maxx<<endl;
        if(k%2){
            sum+=maxx;
        }
        ans=max(ans,sum);
        //cout<<i<<" "<<ans<<endl;
    }
    cout<<n-ans;
    return 0;
}
