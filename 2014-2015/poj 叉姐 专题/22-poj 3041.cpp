#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <set>
#include <queue>
#include <vector>
#include <map>
#include <stack>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define Max 520
int mp[Max][Max];
int cx[Max],cy[Max];
int vis[Max];
int n,m,x,y;
bool dfs(int u)
{
	for(int v=1;v<=n;v++)
	{
		if(mp[u][v]&&!vis[v])
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
	cin>>n>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>x>>y;
		mp[x][y]=1;
	}
	int res=0;
	for(int i=1;i<=n;i++)
	{
		memset(vis,0,sizeof(vis));
		if(dfs(i)) res++;
	}
	cout<<res<<endl;
	return 0;
}
