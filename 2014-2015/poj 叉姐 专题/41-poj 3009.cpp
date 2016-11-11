#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <stack>
#include <queue>
#include <vector>
#include <map>
#include <set>
using namespace std;
#define Max 233
int xx[5]={0,-1,0,1,0};
int yy[5]={0,0,1,0,-1};

int w,h,mp[Max][Max],vis[Max][Max],sx,sy,gx,gy,step,cnt;
void dfs(int x,int y)
{
    if(step>10) return ;
    for(int i=1;i<=4;i++)
    {
        int x1,y1,flag=0;
        x1=x+xx[i];y1=y+yy[i];
        while(x1>=1&&x1<=w&&y1>=1&&y1<=h&&mp[x1][y1]!=1)
        {
            flag=1;
            if(x1==gx&&y1==gy) if(step<cnt) cnt=step;
            x1+=xx[i];y1+=yy[i];
        }
        if(mp[x1][y1]==1&&flag)
        {
            step++;mp[x1][y1]=0;
            dfs(x1-xx[i],y1-yy[i]);
            step--;mp[x1][y1]=1;
        }
    }
}
int main()
{
    while(cin>>w>>h)
    {
        memset(mp,0,sizeof(mp));
        if(w==0&&h==0) break;
        for(int i=1;i<=h;i++)
        {
            for(int j=1;j<=w;j++)
            {
                cin>>mp[j][i];
                if(mp[j][i]==2)
                {
                    sx=j;sy=i;
                }
                if(mp[j][i]==3)
                {
                    gx=j;gy=i;
                }
            }
        }
        cnt=1000000;
        step=1;
        dfs(sx,sy);
        if(cnt>10) cout<<"-1"<<endl;
        else cout<<cnt<<endl;
    }
    return 0;
}
