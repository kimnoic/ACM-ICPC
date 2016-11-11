#include <bits/stdc++.h>
using namespace std;
#define Max 432
int mp[Max][Max];
int n,m;
int vis[Max];
int flag;
int bfs(){
    vis[1]=1;
    queue<int>q;
    q.push(1);
    while(!q.empty()){
        int tmp=q.front();
        q.pop();
        for(int i=1;i<=n;i++){
            if(mp[tmp][i]==flag&&!vis[i]){
                vis[i]=1;
                q.push(i);
                vis[i]=vis[tmp]+1;
            }
        }
        if(vis[n]){
            return vis[n]-1;
        }
    }
    return -1;
}

int main(){
    cin>>n>>m;
    int a,b;
    for(int i=1;i<=m;i++){
        cin>>a>>b;
        mp[a][b]=1;
        mp[b][a]=1;
    }
    flag=0;
    if(mp[1][n]==1) flag=0;
    else flag=1;
    cout<<bfs();
    return 0;
}
