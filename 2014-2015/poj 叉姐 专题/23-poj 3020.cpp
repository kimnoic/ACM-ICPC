#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <stack>
using namespace std;
#define Max 500
int T;
int cx[Max],cy[Max],w,h,grid[Max][Max],v1,v2,vis[Max],cnt;
int mp[Max][Max];
char t;
int xn[5]={0,-1,0,1,0};
int ynn[5]={0,0,1,0,-1};
bool dfs(int u)
{
	for(int v=1;v<=v2;v++)
	{
		if(grid[u][v]&&!vis[v])
		{
			vis[v]=1;
			if(cy[v]==0||dfs(cy[v]))
			{
				cx[u]=v;
				cy[v]=u;
				return true;
			}
		}
	}
	return false;
}
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>h>>w;
		v1=v2=cnt=0;
		memset(grid,0,sizeof(grid));
		memset(cx,0,sizeof(cx));
		memset(cy,0,sizeof(cy));
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=h;i++)
		{
			for(int j=1;j<=w;j++)
			{
				cin>>t;
				if(t=='*')
					mp[j][i]=++cnt;
			}
		}
		for(int j=1;j<=h;j++)
		{
			for(int i=1;i<=w;i++)
			{
				if(mp[i][j]!=0)
				for(int k=1;k<=4;k++)
				{
					int xx=i+xn[k];
					int yy=j+ynn[k];
					if(xx>=1&&xx<=w&&yy>=1&&yy<=h)
					{
						if(mp[xx][yy])
						{
							grid[mp[i][j]][mp[xx][yy]]=1;
						}
					}
				}
			}
		}
		int res=0;
		v1=v2=cnt;
		for(int i=1;i<=v1;i++)
		{
			memset(vis,0,sizeof(vis));
			if(dfs(i))
				res++;
		}
		cout<<cnt-res/2<<endl;
	}
	return 0;
}
