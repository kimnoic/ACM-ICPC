#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
#include<set>
#include<map>
#include<vector>
#include <bits/stdc++.h>
#pragma comment(linker,"/STACK:102400000,102400000")
#define inf 1000000000
#define P 1000003
#define ll long long
using namespace std;
inline int read()
{
    int x=0;char ch=getchar();
    while(ch<'0'||ch>'9')ch=getchar();
    while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
    return x;
}
int n,K,cnt,rt,sum,top;
int id[100005],f[100005],size[100005],last[100005];
int ans1,ans2;
ll tmp[100005],val[100005],dis[100005];
ll ine[1000005],mp[1000005];
bool vis[100005];
struct edge{
    int to,next;
}e[200005];
void pre()
{
    ine[1]=1;
    for(int i=2;i<P;i++)
    {
        int a=P/i,b=P%i;
        ine[i]=(ine[b]*(-a)%P+P)%P;
    }
}
void insert(int u,int v)
{
    e[++cnt].to=v;e[cnt].next=last[u];last[u]=cnt;
    e[++cnt].to=u;e[cnt].next=last[v];last[v]=cnt;
}
void getrt(int x,int fa)
{
    f[x]=0;size[x]=1;
    for(int i=last[x];i;i=e[i].next)
        if(!vis[e[i].to]&&e[i].to!=fa)
        {
            getrt(e[i].to,x);
            size[x]+=size[e[i].to];
            f[x]=max(f[x],size[e[i].to]);
        }
    f[x]=max(f[x],sum-size[x]);
    if(f[x]<f[rt])rt=x;
}
void dfs(int x,int fa)
{
    tmp[++top]=dis[x];id[top]=x;
    for(int i=last[x];i;i=e[i].next)
        if(!vis[e[i].to]&&e[i].to!=fa)
        {
            dis[e[i].to]=(dis[x]*val[e[i].to])%P;
            dfs(e[i].to,x);
        }
}
void query(int x,int id)
{
    x=ine[x]*K%P;
    int y=mp[x];
    if(y==0)return;
    if(y>id)swap(y,id);
    if(y<ans1||(y==ans1&&id<ans2))
        ans1=y,ans2=id;
}
void solve(int x)
{
    vis[x]=1;
    mp[val[x]]=x;
    for(int i=last[x];i;i=e[i].next)
        if(!vis[e[i].to])
        {
            top=0;dis[e[i].to]=val[e[i].to];
            dfs(e[i].to,x);
            for(int j=1;j<=top;j++)query(tmp[j],id[j]);
            top=0;dis[e[i].to]=(val[x]*val[e[i].to])%P;
            dfs(e[i].to,x);
            for(int j=1;j<=top;j++)
            {
                int now=mp[tmp[j]];
                if(!now||id[j]<now)mp[tmp[j]]=id[j];
            }
        }
    mp[val[x]]=0;
    for(int i=last[x];i;i=e[i].next)
         if(!vis[e[i].to])
        {
            top=0;dis[e[i].to]=(val[x]*val[e[i].to])%P;
            dfs(e[i].to,x);
            for(int j=1;j<=top;j++)
                mp[tmp[j]]=0;
        }
    for(int i=last[x];i;i=e[i].next)
        if(!vis[e[i].to])
        {
            rt=0;sum=size[e[i].to];
            getrt(e[i].to,0);
            solve(rt);
        }
}
int main()
{
    freopen("in.txt","r",stdin);
    pre();
    while(scanf("%d%d",&n,&K)!=EOF)
    {
        memset(vis,0,sizeof(vis));
        cnt=0;ans1=ans2=inf;
        memset(last,0,sizeof(last));
        for(int i=1;i<=K;i++) val[i]=read();
        for(int i=1;i<=n;i++)val[i]=read();
        for(int i=1;i<n;i++)
        {
            int u=read(),v=read();
            insert(u,v);
        }
        rt=0;sum=n;f[0]=n+1;
        getrt(1,0);
        cout<<rt<<endl;
        solve(rt);
        if(ans1==inf)puts("No solution");
        else printf("%d %d\n",ans1,ans2);
    }
    return 0;
}
