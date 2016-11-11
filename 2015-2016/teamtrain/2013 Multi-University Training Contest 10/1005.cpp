#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <algorithm>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
const int maxn = 110;
const int inf= 0x3f3f3f3f;
int f[maxn][maxn],g[maxn][maxn];
int n;
struct pt{
    int u,v,w;
}p[maxn*maxn];
bool cmp(pt a,pt b){
    return a.w>b.w;
}
int cnt=0;
void add_edge(int u,int v,int w){
    cnt++;
    p[cnt].u=u;
    p[cnt].v=v;
    p[cnt].w=w;
}
int fa[maxn],vis[maxn];
void init(){
    for(int i=1;i<=n;i++) fa[i]=i;
    cnt=0;
    //memset(vis,0,sizeof(vis));
    memset(g,0,sizeof(g));
    for(int i=1;i<=n;i++) g[i][i]=-1;
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++) cin>>f[i][j];
    }
    for(int i=1;i<=n;i++){
        for(int j=i+1;j<=n;j++){
            if(f[i][j]>0){
                add_edge(i,j,f[i][j]);
            }
        }
    }
    sort(p+1,p+cnt+1,cmp);
}
int findf(int x){
    if(fa[x]==x) return x;
    else return findf(fa[x]);
}

void solve(){
    //cout<<cnt<<endl;
    for(int i=1;i<=cnt;i++){
        //cout<<i<<endl;
        int u=p[i].u;
        int v=p[i].v;
        int t1=findf(u);
        int t2=findf(v);
        if(t1!=t2){
            //fa[t2]=t1;
            g[u][v]=p[i].w;
            g[v][u]=p[i].w;
            int tmp=u,temp=fa[u];
            int tm=fa[temp];
            if(temp==tm){
                fa[temp]=tmp;
                fa[tmp]=v;
                continue;
            }
            while(tm!=temp){
                fa[temp]=tmp;
                tmp=temp;
                temp=tm;
                tm=fa[tm];
            }
            fa[temp]=tmp;
            fa[u]=v;
        }
        else {
            memset(vis,0,sizeof(vis));
            int minn=inf;
            int temp=u;
            while(temp!=fa[temp]){
                vis[temp]=1;
                temp=fa[temp];
            }
            vis[temp]=1;
            temp=v;
            while(temp!=fa[temp]){
                minn=min(minn,g[temp][fa[temp]]);
                if(vis[fa[temp]]) {
                    break;
                }
                temp=fa[temp];
            }
            int tm=fa[temp];
            temp=u;
            while(temp!=tm){
                minn=min(minn,g[temp][fa[temp]]);
                temp=fa[temp];
            }
            if(minn!=p[i].w){
                //cout<<p[i].u<<" "<<p[i].v<<endl;
                //cout<<minn<<endl;
                cout<<"NO"<<endl;
                return ;
            }
        }
    }
    cout<<"YES"<<endl;
    for(int i=1;i<=n;i++){
        for(int j=1;j<n;j++){
            cout<<g[i][j]<<" ";
        }
        cout<<g[i][n]<<endl;
    }
}
int main(){
    while(~scanf("%d",&n)){
        init();
        solve();
    }
    return 0;
}
/*
4
-1 3 4 3
3 -1 3 3
4 3 -1 3
3 3 3 -1
*/
