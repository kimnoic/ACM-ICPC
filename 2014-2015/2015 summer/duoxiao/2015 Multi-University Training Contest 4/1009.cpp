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
    queue<pt>q;
    while(!q.empty())
    {
        q.pop();
    }
    pt tmp;
    if(!judge(x,y)) return ;
    vis[x][y]=1;
    tmp.x=x;tmp.y=y;
    q.push(tmp);
    while(!q.empty())
    {
        pt cur=q.front();
        q.pop();
        for(int i=1;i<=4;i++)
        {
            if(judge(cur.x+xx[i],cur.y+yy[i]))
            {
                tmp.x=cur.x+xx[i];
                tmp.y=cur.y+yy[i];
                vis[tmp.x][tmp.y]=1;
                q.push(tmp);
                ress=max(ress,tmp.x+tmp.y);
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
        memset(vis,0,sizeof(vis));
        getchar();
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=m;j++)
            {
                //cin>>mp[j][i];
                //mp[j][i]='0';
                scanf("%c",&mp[j][i]);
            }
            getchar();
        }
        ress=2;
        bfs(1,1);
        queue <pt> Q;
        queue <pt> q;
        while(!Q.empty()) Q.pop();
        while(!q.empty()) q.pop();
        memset(vis,0,sizeof(vis));
        pt t;
        for(int i=1;i<=ress-1;i++)
        {
            t.x=ress-i;
            t.y=i;
            if(mp[t.x][t.y]=='0')
            {
                Q.push(t);
                vis[t.x][t.y]=1;
            }
        }
        if(Q.empty())
        {
            for(int i=1;i<=ress-1;i++)
            {
                t.x=ress-i;
                t.y=i;
                Q.push(t);
                vis[t.x][t.y]=1;
            }
        }
        queue <pt > QQ;
        queue <pt> tq;
        while(!QQ.empty()) QQ.pop();
        int f=1;
        pt y=Q.front();
        if(mp[y.x][y.y]=='1')
        {
            flag=1;
            cout<<1;
        }
        if(ress==n+m)
        {
            cout<<0<<endl;
            continue;
        }
        while(ress<n+m)
        {
            while(!tq.empty()) tq.pop();
            if(f==1)
            {
                while(!tq.empty()) tq.pop();
                int cnt=0;
                while(!Q.empty())
                {
                    pt tt=Q.front();
                    //cout<<tt.x<<" "<<tt.y<<endl;
                    tq.push(tt);
                    Q.pop();
                    pt tm;
                    tm.x=tt.x+1;
                    tm.y=tt.y;
                    //cout<<tm.x<<" "<<tm.y<<endl;
                    if(jj(tm.x,tm.y)&&vis[tm.x][tm.y]==0&&mp[tm.x][tm.y]=='0')
                    {
                        q.push(tm);
                        //cout<<ress<<" a"<<endl;
                        vis[tm.x][tm.y]=1;
                    }
                    tm.x=tt.x;
                    tm.y=tt.y+1;
                    if(jj(tm.x,tm.y)&&vis[tm.x][tm.y]==0&&mp[tm.x][tm.y]=='0')
                    {
                        q.push(tm);
                        //cout<<ress<<" a"<<endl;
                        vis[tm.x][tm.y]=1;
                    }
                }
                if(q.empty())
                {
                    //cout<<ress<<endl;
                    flag=1;
                    for(int i=1;i<ress;i++)
                    {
                        vis[i][ress-i]=0;
                    }
                    while(!tq.empty())
                    {
                        pt tt=tq.front();
                        //cout<<tt.x<<" "<<tt.y<<endl;
                        tq.pop();
                        pt tm;
                        tm.x=tt.x+1;
                        tm.y=tt.y;
                        if(jj(tm.x,tm.y)&&vis[tm.x][tm.y]==0)
                        {
                            q.push(tm);
                            vis[tm.x][tm.y]=1;
                            //cout<<"a"<<endl;
                        }
                        tm.x=tt.x;
                        tm.y=tt.y+1;
                        if(jj(tm.x,tm.y)&&vis[tm.x][tm.y]==0)
                        {
                            q.push(tm);
                            vis[tm.x][tm.y]=1;
                        }
                    }
                    cout<<1;
                }
                else if(!flag);
                else cout<<0;
                f=0;
            }
            else
            {
                //cout<<"a"<<endl;
                while(!tq.empty()) tq.pop();
                int cnt=0;
                while(!q.empty())
                {
                    pt tt=q.front();
                    //cout<<tt.x<<" "<<tt.y<<endl;
                    tq.push(tt);
                    q.pop();
                    pt tm;
                    tm.x=tt.x+1;
                    tm.y=tt.y;
                    if(jj(tm.x,tm.y)&&vis[tm.x][tm.y]==0&&mp[tm.x][tm.y]=='0')
                    {
                        Q.push(tm);
                        vis[tm.x][tm.y]=1;
                    }
                    tm.x=tt.x;
                    tm.y=tt.y+1;
                    if(jj(tm.x,tm.y)&&vis[tm.x][tm.y]==0&&mp[tm.x][tm.y]=='0')
                    {
                        Q.push(tm);
                        vis[tm.x][tm.y]=1;
                    }
                }
                if(Q.empty())
                {
                    flag=1;
                    for(int i=1;i<ress;i++)
                    {
                        vis[i][ress-i]=0;
                    }
                    while(!tq.empty())
                    {
                        pt tt=tq.front();
                        tq.pop();
                        pt tm;
                        tm.x=tt.x+1;
                        tm.y=tt.y;
                        //cout<<tt.x<<" "<<tt.y<<endl;
                        if(jj(tm.x,tm.y)&&vis[tm.x][tm.y]==0)
                        {
                            Q.push(tm);
                            vis[tm.x][tm.y]=1;
                        }
                        tm.x=tt.x;
                        tm.y=tt.y+1;
                        if(jj(tm.x,tm.y)&&vis[tm.x][tm.y]==0)
                        {
                            Q.push(tm);
                            vis[tm.x][tm.y]=1;
                            //cout<<tm.x<<" "<<tm.y<<endl;
                        }
                    }
                    cout<<1;
                }
                else if(!flag);
                else cout<<0;
                f=1;
            }
            ress++;
        }
        if(!flag) cout<<0;
        cout<<endl;
    }
    return 0;
}
