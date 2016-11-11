#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>

using namespace std;
char g[1005][1005];
int vis[1005][1005];
char ans[5005];
int top=0;
int dirx[4]= {0,0,-1,1};
int diry[4]= {1,-1,0,0};
int n,m;
bool dp[1005][1005];
int legal(int x,int y)
{
    if(x<1||x>n||y<1||y>m)
        return 0;
    return 1;
}
int mn;
queue < pair<int,int> > q;
void bfs(int x,int y)
{
    while(!q.empty())
        q.pop();
    q.push(make_pair(x,y));
    while(!q.empty())
    {
        int x=q.front().first;
        int y=q.front().second;
        q.pop();
        if(vis[x][y]<1000009)
            continue;
        if(g[x][y]=='1')
        {
            vis[x][y]=n-x+m-y;
            mn=min(mn,n-x+m-y);
            continue;
        }
        vis[x][y]=n-x+m-y;
        mn=min(mn,n-x+m-y);
        for(int k=0; k<4; k++)
            if(legal(x+dirx[k],y+diry[k]))
                q.push(make_pair(x+dirx[k],y+diry[k]));
    }
}
int main()
{
    int cas;
    scanf("%d",&cas);
    while(cas--)
    {
        memset(vis,0x3f,sizeof(vis));
        mn=1000000009;
        n=m=1000;
        scanf("%d %d",&n,&m);
        for(int i=1; i<=n; i++)
        {
            scanf(" %s",g[i]+1);
        }
        bfs(1,1);
        if(mn==0&&g[n][m]=='0')
        {
            cout<<0<<endl;
            continue;
        }

        memset(dp,0,sizeof(dp));
        for(int i=1; i<=n; i++)
            for(int j=1; j<=m; j++)
                if(vis[i][j]==mn)
                    dp[i][j]=1;
        mn--;
        top=0;
        ans[top++]='1';
        while(mn>=0)
        {
            int flag=1;
            for(int j=m; j>=1; j--)
            {
                int i=n+m-j-mn;
                if(i<1||i>n)
                    continue;
                if(i==1)
                {
                    if(dp[i][j-1]==0)
                        continue;
                }
                else if(j==1)
                {
                    if(dp[i-1][j]==0)
                        continue;
                }
                else if(dp[i-1][j]==0&&dp[i][j-1]==0)
                    continue;
                if(g[i][j]=='0')
                    flag=0;
            }
            if(flag)
            {
                for(int j=m; j>=1; j--)
                {
                    int i=n+m-j-mn;
                    if(i<1||i>n)
                        continue;
                    if(i==1)
                    {
                        if(dp[i][j-1]==0)
                            continue;
                    }
                    else if(j==1)
                    {
                        if(dp[i-1][j]==0)
                            continue;
                    }
                    else if(dp[i-1][j]==0&&dp[i][j-1]==0)
                        continue;
                    dp[i][j]=1;
                }
            }
            else
            {
                for(int j=m; j>=1; j--)
                {
                    int i=n+m-j-mn;
                    if(i<1||i>n)
                        continue;
                    if(i==1)
                    {
                        if(dp[i][j-1]==0)
                            continue;
                    }
                    else if(j==1)
                    {
                        if(dp[i-1][j]==0)
                            continue;
                    }
                    else if(dp[i-1][j]==0&&dp[i][j-1]==0)
                        continue;
                    if(g[i][j]=='0')
                        dp[i][j]=1;
                }
            }
            mn--;
            ans[top++]='0'+flag;
        }
        for(int i=0; i<top; i++)
            printf("%c",ans[i]);
        puts("");
    }
    return 0;
}
