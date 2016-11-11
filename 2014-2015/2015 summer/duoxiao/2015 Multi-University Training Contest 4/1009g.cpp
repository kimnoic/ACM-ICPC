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
int n,m;
#define Max 2010
int vis[Max][Max];
char mp[Max][Max];
struct pt
{
    int x,y;
};
int xx[5]={0,-1,0,1,0};
int yy[5]={0,0,1,0,-1};
int qx[Max*Max],qy[Max*Max];
int ress;
bool judge(int x,int y)
{
    if(x>=1&&x<=m&&y>=1&&y<=n&&vis[x][y]==0&&mp[x][y]=='0') return true;
    else return false;
}
bool jj(int x,int y)
{
    if(x>=1&&x<=m&&y>=1&&y<=n) return true;
    else return false;
}
void bfs(int x,int y)
{
    memset(qx,0,sizeof(qx));
    memset(qy,0,sizeof(qy));
    int top=1,all=1;
    int ax,ay;
    qx[all]=x;
    qy[all]=y;
    if(!judge(x,y)) return ;
    vis[x][y]=1;
    while(top<=all)
    {
        int tx=qx[top],ty=qy[top];
        //cout<<tx<<" "<<ty<<endl;
        top++;
        for(int i=1;i<=4;i++)
        {
            if(judge(tx+xx[i],ty+yy[i]))
            {
                ax=tx+xx[i];
                ay=ty+yy[i];
                vis[ax][ay]=1;
                qx[++all]=ax;
                qy[all]=ay;
                ress=max(ress,ax+ay);
            }
        }
    }
}

int main()
{
    int T;
    cin>>T;
    int flag=0;
    while(T--)
    {
        cin>>n>>m;
        flag=0;
        memset(vis,0,sizeof(vis));
        getchar();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                //cin>>mp[j][i];
                scanf("%c",&mp[j][i]);
            }
            getchar();
        }
        ress=2;
        bfs(1,1);

        pt t;
        int cnt=0;
        for(int i=1;i<=ress-1;i++)
        {
            t.x=ress-i;
            t.y=i;
            if(mp[t.x][t.y]=='0')
            {
                cnt++;
                vis[t.x][t.y]=1;
            }
        }
        if(cnt==0)
        {
            for(int i=1;i<=ress-1;i++)
            {
                t.x=ress-i;
                t.y=i;
                vis[t.x][t.y]=1;
            }
        }
        int xxx=qx[1];
        int yyy=qy[1];
        if(mp[xxx][yyy]=='1')
        {
            flag=1;
            cout<<1;
        }
        if(ress==n+m&&mp[xxx][yyy]=='0')
        {
            cout<<0<<endl;
            continue;
        }
        while(ress<n+m)
        {
            int ff=1;
            int cnt=0;
            int x;
            if(ress>=m) x=m;
            else x=ress;
            int y=ress-x+1;
            while(y<=n&&x>=1)
            {
                if(vis[x][y])
                {
                    if(jj(x+1,y)&&vis[x+1][y]==0&&mp[x+1][y]=='0')
                    {
                        vis[x+1][y]=1;
                        cnt++;
                    }
                    if(jj(x,y+1&&vis[x][y+1]==0)&&mp[x][y+1]=='0')
                    {
                        vis[x][y+1]=1;
                        cnt++;
                    }
                }
                x--;
                y++;
            }
            if(cnt==0)
            {
                flag=1;
                if(ress>m) x=m;
                else x=ress;
                y=ress-x;
                while(y<=n&&x>=1)
                {
                    if(vis[x][y])
                    {
                        if(jj(x+1,y)&&vis[x+1][y]==0)
                        {
                            vis[x+1][y]=1;
                        }
                        if(jj(x,y+1&&vis[x][y+1]==0))
                        {
                            vis[x][y+1]=1;
                        }
                    }
                    x--;
                    y++;

                }
                cout<<1;
            }
            else if(flag) cout<<0;
            ress++;
        }
        if(!flag) cout<<0;
        cout<<endl;
    }
    return 0;
}
