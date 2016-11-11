#include<bits/stdc++.h>
using namespace std;
const int maxn = 2333;
struct pt{
    int x,y,nxt;
}s[maxn*2];
int fst[maxn];
int m,tn,n;
int k;
const int inf = 0x3f3f3f3f;
int uu;
void addedge(int x,int y){
    uu++;
    n++;
    s[n].x=x;s[n].y=y;
    s[n].nxt=fst[x];fst[x]=n;
}
int down,up;
int hasdown[maxn];
int hasup[maxn];
int totup[maxn];
int totdown[maxn];
int dep[maxn];

void dfs(int u,int fa){
    hasup[u]=hasdown[u]=0;
    if(dep[u]==up)hasup[u]=1;
    if(dep[u]==down)hasdown[u]=1;
    if(dep[u]<=up)totup[u]=1;
    if(dep[u]<=down)totdown[u]=1;
    if(dep[u]==up)
        return;
    for(int e=fst[u];e!=-1;e=s[e].nxt){
        int v=s[e].y;
        if(v!=fa){
            dep[v]=dep[u]+1;
            dfs(v,u);
            uu++;
            totup[u]+=totup[v];
            totdown[u]+=totdown[v];
            hasup[u]+=hasup[v];
            hasdown[u]+=hasdown[v];
        }
    }
}

int calc(int root){
    int tot = totdown[root];
    int maxc = 0;
    if(up!=down){
        for(int e=fst[root];e!=-1;e=s[e].nxt){
            int v=s[e].y;
            uu++;
            maxc=max(maxc,hasup[v]);
        }
        tot+=maxc;
    }
    return m-tot;
}



int main(){
    cin>>m>>k;int x,y;
    up=(k+1)/2;
    down=k/2;
    memset(fst,-1,sizeof(fst));
    for(int i=1;i<m;i++){
        cin>>x>>y;
        addedge(x,y);
        uu++;
        addedge(y,x);
    }
    int ans = inf;
    for(int i = 1;i<=m;i++){
        memset(totup,0,sizeof(totup));
        memset(totdown,0,sizeof(totdown));
        dep[i]=0;
        uu++;
        dfs(i,-1);
        ans=min(ans,calc(i));
    }
    cout<<ans<<endl;
    return 0;
}
