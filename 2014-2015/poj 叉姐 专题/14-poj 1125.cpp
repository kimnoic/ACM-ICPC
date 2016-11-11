#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <stack>
#include <math.h>
#include <map>
#include <set>
#include <vector>
#include <stdlib.h>
using namespace std;
//const int inf=20;
#define inf 1<<20
int mp[233][233];
int n;
int p,x,y;
void floyd()
{
	for(int k=1;k<=n;k++)
	{
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j&&mp[i][j]>mp[i][k]+mp[k][j])
				{
					mp[i][j]=mp[i][k]+mp[k][j];
				}
			}
		}
	}
	int maxx=0;
	int minn=inf,pos;
	for(int i=1;i<=n;i++)
	{
		maxx=0;
		for(int j=1;j<=n;j++)
		{
			if(i!=j&&maxx<mp[i][j])
			{
				maxx=mp[i][j];
			}
		}
		if(minn>maxx)
		{
			minn=maxx;
			pos=i;
		}
	}
	if(minn>=inf) cout<<"disjoint"<<endl;
	else cout<<pos<<" "<<minn<<endl;
}
int main()
{
	while(cin>>n)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			mp[i][j]=inf;
		//memset(mp,inf,sizeof(mp));
		if(!n) break;
		for(int i=1;i<=n;i++)
		{
			cin>>p;
			for(int j=1;j<=p;j++)
			{
				cin>>x>>y;
				mp[i][x]=y;
			}
		}
		floyd();
	}
	return 0;
}
