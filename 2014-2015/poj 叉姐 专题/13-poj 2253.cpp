#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#include <set>
#include <math.h>
using namespace std;
#define Max 233
#define INF 1<<30
double mp[Max][Max];
double x[Max],y[Max],d[Max];
double t;
int n,p[Max],vis[Max];
void dijistra()
{
	memset(vis,0,sizeof(vis));
	for(int i=1;i<=n;i++) d[i]=INF;
	d[1]=0;
	for(int i=1;i<=n;i++)
	{
		long long minn=INF;
		int u=1;
		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&d[j]<minn)
			{
				minn=d[j];
				u=j;
			}
		}
		cout<<u<<endl;
		vis[u]=1;
		if(u==2) break;

		for(int j=1;j<=n;j++)
		{
			if(!vis[j]&&max(d[u],mp[u][j])<d[j])
			{
				d[j]=max(d[u],mp[u][j]);
			}
		}
	}
}
int main()
{
	int cnt=1;
	while(cin>>n)
	{
		memset(mp,0,sizeof(mp));
		if(n==0) break;
		for(int i=1;i<=n;i++)
		{
			cin>>x[i]>>y[i];
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				t=sqrt((x[j]-x[i])*(x[j]-x[i])+(y[i]-y[j])*(y[i]-y[j]));
				mp[i][j]=t;
				mp[j][i]=t;
			}
		}
		dijistra();
		printf("Scenario #%d\nFrog Distance = %.3lf\n\n",cnt++,d[2]);
	}
	return 0;
}
