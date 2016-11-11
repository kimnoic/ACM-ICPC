#include <stdio.h>
#include <algorithm>
#include <string.h>
#define mst memset
#define smax std::max
#define ssort std::sort
const int maxn=2e4+100;
struct pt{int v,next,w;}edge[maxn];
int n,k,head[maxn],e,vis[maxn],ans,root,num;
void init(){
    mst(vis,0,sizeof(vis));
    mst(head,-1,sizeof(head));
    e=ans=0;
}
void add(int u,int v,int w){
    edge[e].v=v;edge[e].w=w;edge[e].next=head[u];head[u]=e++;
}
int mx[maxn],sz[maxn],mi,dis[maxn];
void dfssz(int u,int fa){
    sz[u]=1;
    mx[u]=0;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v!=fa && !vis[v]){
            dfssz(v,u);
            sz[u]+=sz[v];
            if(sz[v]>mx[u]) mx[u]=sz[v];
        }
    }
}
void dfsroot(int r,int u,int fa){
    mx[u]=smax(mx[u],sz[r]-sz[u]);
    if(mx[u]<mi) mi=mx[u],root=u;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v!=fa && !vis[v]) dfsroot(r,v,u);
    }
}
void dfsdis(int u,int d,int fa){
    dis[num++]=d;
    for(int i=head[u];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(v!=fa && !vis[v]) dfsdis(v,d+edge[i].w,u);
    }
}
int calc(int u,int d){
    int ret=0;
    num=0;
    dfsdis(u,d,0);
    ssort(dis,dis+num);
    int i=0,j=num-1;
    while(i<j){
        if(dis[i]+dis[j]>k) j--;
        else if(dis[i]+dis[j]<k) i++;
        else {
            if(dis[i]==dis[j]){
                ret+=(j-i)*(j-i+1)/2;
                break;
            }
            int st=i;
            while(dis[st]==dis[i]) st++;
            int ed=j;
            while(dis[ed]==dis[j]) ed--;
            ret+=(st-i)*(j-ed);
            i=st;
            j=ed;
        }
    }
    return ret;
}
void dfs(int u){
    mi=n;
    dfssz(u,0);
    dfsroot(u,u,0);
    ans+=calc(root,0);
    vis[root]=1;
    for(int i=head[root];i!=-1;i=edge[i].next){
        int v=edge[i].v;
        if(!vis[v]){
            ans-=calc(v,edge[i].w);
            dfs(v);
        }
    }
}
int main(){
    while(~scanf("%d",&n)&&n){
        init();
        int u,v,w;
        for(int i=1;i<=n;i++){
            while(~scanf("%d",&v)&&v){
                scanf("%d",&w);
                add(i,v,w);
                add(v,i,w);
            }
        }
        while(~scanf("%d",&k)&&k){
            ans=0;
            mst(vis,0,sizeof(vis));
            dfs(1);
            if(ans>0)puts("AYE");
            else puts("NAY");
        }
        puts(".");
        //printf("%d\n",ans);
    }
    return 0;
}
