#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
#define N 125
int uN,vN;
int g[N][N];
int match[N];
int vis[N];
int dfs(int u)
{
    for(int i=1;i<=vN;i++)
      if(g[u][i]&&!vis[i])
      {
          vis[i]=1;
          if(match[i]==-1||dfs(match[i]))
          {
              match[i]=u;
              return 1;
          }
      }
    return 0;
}
int hungary()
{
    int sum=0;
    memset(match,-1,sizeof(match));
    for(int i=1;i<=uN;i++)
    {
        memset(vis,0,sizeof(vis));
        if(dfs(i)) sum++;
    }
    return sum;
}
int main()
{
    int t,n,m;
    cin>>t;
    int a,b;
    while(t--)
    {
        scanf("%d%d",&n,&m);
        memset(g,0,sizeof(g));
        for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            g[a][b]=1;
        }
        uN=vN=n;
        printf("%d\n",n-hungary());
    }
    return 0;
}
