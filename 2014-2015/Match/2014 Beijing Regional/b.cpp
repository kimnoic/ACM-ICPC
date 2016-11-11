#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
using namespace std;
int cnt[25];
int mp[6][6];
int n,m,k;
bool flag,ttt;
void print()
{
    flag=false;
    ttt=true;
    printf("YES\n");
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=m;j++)
            printf("%d ",mp[i][j]);
        printf("\n");
    }
}
bool check(int x,int y)
{
    int max_=0;
    for (int i=1;i<=k;i++)
        max_=max(max_,cnt[i]);
    int w=0,b=0;
    int xx=n-x+1;
    int yy=m;
    w+=xx*yy>>1;
    b=w;
    if (xx%2==1&&yy%2==1) w++;
    w-=y>>1;
    b-=y>>1;
    if (y%2==1) w--;
    int q=max(w,b);
    if (max_>q) return false;
    return true;
}
void dfs(int t,int color)
{
    if (ttt) return ;
    int x=(t-1)/m+1;
    int y=t-(x-1)*m;
    if (color==mp[x-1][y]||color==mp[x][y-1]) return;
    mp[x][y]=color;
    if (t==n*m)
    {
        print();
        mp[x][y]=-1;
        return;
    }
    if (!check(x,y))
    {
        mp[x][y]=-1;
        return ;
    }
    for (int i=1;i<=k;i++)
    if (cnt[i])
    {
        cnt[i]--;
        dfs(t+1,i);
        cnt[i]++;
    }
    mp[x][y]=-1;
}
int main(int argc, const char * argv[])
{
    int i,case_=0,T;
    cin>>T;
    memset(mp,-1,sizeof(mp));
    while (T--)
    {
        scanf("%d%d%d",&n,&m,&k);
        ttt=false;
        printf("Case #%d:\n",++case_);
        flag=true;
        memset(cnt,0,sizeof(cnt));
        for (i=1;i<=k;i++)
            scanf("%d",cnt+i);
        for (i=1;i<=k;i++)
        {
            cnt[i]--;
            dfs(1,i);
            cnt[i]++;
        }
        if (flag) printf("NO\n");
    }
    return 0;
}
