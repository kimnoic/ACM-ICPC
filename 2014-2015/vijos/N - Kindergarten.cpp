#include <stdio.h>
#include <string.h>
#define N 205
#include <iostream>
using namespace std;
int g[N][N];
int match[N];
int vis[N];
int B,G,m;
int dfs(int u)
{
     for(int i=1;i<=G;i++)
         if(!vis[i] && !g[u][i]){
             vis[i]=1;
             if(match[i]==-1 || dfs(match[i])){
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
     for(int i=1;i<=B;i++){
         memset(vis,0,sizeof(vis));
         sum+=dfs(i);
     }
     return sum;
}
int main(void)
{
     int a,b;
     int t;
     cin>>t;
     while(t--)
     {
         scanf("%d%d",&B,&m);
         G=B;
         memset(g,0,sizeof(g));
         for(int i=1;i<=m;i++)
        {
            scanf("%d%d",&a,&b);
            g[a][b]=1;
        }
        printf("%d\n",G-hungary());
    }
    return 0;
}
