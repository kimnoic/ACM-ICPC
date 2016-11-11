#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <set>
#include <map>
using namespace std;
char mp[33][33][33];
int l,r,c,sx,sy,sz,ex,ey,ez;
struct pt
{
    int x,y,z,step;
};
int xx[8]={0,-1,1,0,0,0,0,0};
int yy[8]={0,0,0,1,-1,0,0,0};
int zz[8]={0,0,0,0,0,-1,1,0};
int bfs()
{
    pt p;
    p.x=sx,p.y=sy,p.z=sz;p.step=0;
    queue<pt> q;
    q.push(p);
    while(!q.empty())
    {
        pt e=q.front();
        if(e.x==ex&&e.y==ey&&e.z==ez) return e.step;
        q.pop();
        int xn,yn,zn;
        for(int i=1;i<=6;i++)
        {
            xn=e.x+xx[i];
            yn=e.y+yy[i];
            zn=e.z+zz[i];
            p.step=e.step+1;
            p.x=xn;p.y=yn;p.z=zn;
            if(xn>=1&&xn<=c&&yn>=1&&yn<=r&&zn>=1&&zn<=l&&mp[xn][yn][zn]!='#')
            {
                q.push(p);
                mp[xn][yn][zn]='#';
            }
        }
    }
    return -1;
}
int main()
{
    while(cin>>l>>r>>c)
    {
        if(l==0&&r==0&&c==0) break;
        for(int i=1;i<=l;i++)
        {
            for(int j=1;j<=r;j++)
            {
                for(int k=1;k<=c;k++)
                {
                    cin>>mp[k][j][i];
                    if(mp[k][j][i]=='S')
                    {
                        sx=k;sy=j;sz=i;
                    }
                    else if(mp[k][j][i]=='E')
                    {
                        ex=k;ey=j;ez=i;
                    }
                }
            }
        }
        int cnt=bfs();
        if(cnt!=-1)
        cout<<"Escaped in "<<cnt<<" minute(s)."<<endl;
        else cout<<"Trapped!"<<endl;
    }
    return 0;
}
