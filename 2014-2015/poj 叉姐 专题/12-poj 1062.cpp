#include <iostream>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <stdlib.h>
using namespace std;
#define Max 233
#define INF 1<<30
int mp[Max][Max]={},vis[Max]={};
int pri[Max],lev[Max];
int m,n;
int p,l,x;
int t,v;
int d[Max];
int dijistra()
{
	for(int i=1;i<=n;i++)
	{
        d[i]=pri[i];
	}
	for(int i=1;i<=n;i++)
	{
		int minn=INF,u=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==1&&d[j]<minn)
			{
				minn=d[j];
				u=j;
			}
		}
		if(!u) break;
		vis[u]=0;
		for(int j=1;j<=n;j++)
		{
			if(vis[j]==1&&mp[u][j]>0&&d[u]+mp[u][j]<d[j])
			{
				d[j]=d[u]+mp[u][j];
			}
		}
	}
	return d[1];
}
void rankk()
{
	int ran;
	long long temp=1<<30;
    for(int i=1;i<=n;i++)
	{
		ran=lev[i];
		for(int j=1;j<=n;j++)
		{
			if(lev[j]>ran||ran-lev[j]>m) vis[j]=0;
			else vis[j]=1;
		}
		int t=dijistra();
		if(temp>t) temp=t;
	}
	cout<<temp<<endl;
}
int main()
{
	cin>>m>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>p>>l>>x;
		pri[i]=p;
		lev[i]=l;
		//mp[0][i]=p;
		for(int j=1;j<=x;j++)
		{
			cin>>t>>v;
			mp[t][i]=v;
		}
	}
	rankk();
	return 0;
}
