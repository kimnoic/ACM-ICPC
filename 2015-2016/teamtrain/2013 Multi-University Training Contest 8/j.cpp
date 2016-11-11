#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>
using namespace std;
const int N = 1522;
struct pt{
    int next,to;
    pt(){}
    pt(int a,int b){
        next=a;
        to=b;
    }
}p[N*N];
int head[N],m,n,cnt,k,x,from[N],instack[N],dfn[N],low[N],vst,color,belong[N];
bool vis[N*N],use[N];
vector<int> mp[N];
bool match(int x){
    for(int i=0;i<mp[x].size();i++){
        int v=mp[x][i];
        if(use[v]) continue;
        use[v]=1;
        if(from[v]==-1||match(from[v])){
            from[v]=x;
            return 1;
        }
    }
    return false;
}
void add_edge(int a,int b){
    p[++cnt]=pt(head[a],b);
    head[a]=cnt;
}
vector<int>ans;
void dfs(int u){
    dfn[u]=low[u]=++vst;
    instack[u]=1;
    ans.push_back(u);
    for(int i=head[u];i!=-1;i=p[i].next){
        int v=p[i].to;
        if(vis[i]) continue;
        vis[i]=1;
        if(instack[v]==0) {
            dfs(v);
            low[u]=min(low[u],low[v]);
        }
        else if(instack[v]==1){
            low[u]=min(low[u],dfn[v]);
        }
    }
    if(low[u]==dfn[u]){
        color++;
        while(ans.back()!=u){
            belong[ans.back()]=color;
            instack[ans.back()]=2;
            ans.pop_back();
        }
        belong[ans.back()]=color;
        instack[ans.back()]=2;
        ans.pop_back();
    }
}
void init(){
    cin>>n>>m;
    for(int i=1;i<=n;i++) {
        mp[i].clear();
        cin>>k;
        while(k--){
            cin>>x;
            mp[i].push_back(x);
        }
    }
    memset(from,-1,sizeof(from));
    memset(head,-1,sizeof(head));cnt=-1;
}
void solve(){
    for(int i=1;i<=n;i++){
        memset(use,0,sizeof(use));
        if(match(i)) add_edge(i,0);
        else add_edge(0,i);
    }
    for(int i=1;i<=n;i++){
        for(int j=0;j<mp[i].size();j++){
            int x=mp[i][j];
            if(from[x]==i) add_edge(x+n,i);
            else add_edge(i,x+n);
        }
    }
    for(int i=1;i<=m;i++){
        if(from[i]==-1) add_edge(i+n,n+m+1);
        else add_edge(n+m+1,i+n);
    }
    memset(instack,0,sizeof(instack));
    memset(vis,0,sizeof(vis));
    vst=color=0;ans.clear();
    for(int i=0;i<=n+m+1;i++) if(instack[i]==0) dfs(i);
    for(int i=1;i<=n;i++){
        ans.clear();
        for(int j=0;j<mp[i].size();j++){
            if(belong[i]==belong[mp[i][j]+n] || from[mp[i][j]]==i) ans.push_back(mp[i][j]);
        }
        sort(ans.begin(),ans.end());
        cout<<ans.size();
        for(int j=0;j<ans.size();j++) cout<<" "<<ans[j];
        cout<<endl;
    }
}

int main(){
    int _case=0;
    int T;cin>>T;
        while(T--){
            init();
            cout<<"Case #"<<++_case<<":"<<endl;
            solve();
        }
    return 0;
}
