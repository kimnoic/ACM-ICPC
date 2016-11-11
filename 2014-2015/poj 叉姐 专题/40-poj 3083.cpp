#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
int xx[5]={0,-1,0,1,0};
int yy[5]={0,0,-1,0,1};

int x1[5]={0,1,0,-1,0};
int y11[5]={0,0,1,0,-1};
#define Max 233
char mp[Max][Max];
int vis[Max][Max];
int m,n,T,sx,sy,ex,ey;
bool check(int x,int y)
{
	if(mp[x][y]=='E') return true;
	if(mp[x][y]!='#'&&x>0&&x<=m&&y>0&&y<=n) return true;
	else return false;
}
int step;
int l_dfs(int x,int y,int d,int s)
{
    int dr=d;
    int cnt=0;
    if(x==ex&&y==ey) {return s;}
    dr--;
    if(dr<=0) dr+=4;
    while(cnt<=4)
	{
		cnt++;
		if(check(x+xx[dr],y+yy[dr]))
		{
			return l_dfs(x+xx[dr],y+yy[dr],dr,s+1);
		}
		else
		{
			dr%=4;
			dr++;
		}
	}
}
int r_dfs(int x,int y,int d,int s)
{
	int dr=d;
	int cnt=0;
	if(x==ex&&y==ey) return s;
	dr%=4;
	dr++;
	while(cnt<=4)
	{
		cnt++;
		if(check(x+x1[dr],y+y11[dr]))
		{
			return r_dfs(x+x1[dr],y+y11[dr],dr,s+1);
		}
		else
		{
			dr--;
			if(dr<=0) dr+=4;
		}
	}
}
struct pt
{
	int x,y,s;
};
int bfs()
{
	memset(vis,0,sizeof(vis));
	pt P;
	P.x=sx;
	P.y=sy;
	P.s=1;
	queue < pt > Q;
	Q.push(P);
	while(!Q.empty())
	{
		pt q=Q.front();
		Q.pop();
		if(q.x==ex&&q.y==ey) return q.s;
		pt qq;
		for(int i=1;i<=4;i++)
		{
			qq.x=q.x+xx[i];
			qq.y=q.y+yy[i];
			qq.s=q.s+1;
			if(check(qq.x,qq.y)&&!vis[qq.x][qq.y])
			{
				Q.push(qq);
				vis[qq.x][qq.y]=1;
			}
		}
	}
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>m>>n;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>mp[j][i];
				if(mp[j][i]=='S')
				{
					sx=j;
					sy=i;
				}
				else if(mp[j][i]=='E')
				{
					ex=j;
					ey=i;
				}
			}
		}

		int le=l_dfs(sx,sy,2,1);
		int ri=r_dfs(sx,sy,3,1);
		memset(vis,0,sizeof(vis));
		int bb=bfs();
		cout<<le<<" "<<ri<<" "<<bb<<endl;
	}
	return 0;
}
