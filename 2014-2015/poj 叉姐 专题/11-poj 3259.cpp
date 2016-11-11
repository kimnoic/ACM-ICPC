#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <stdlib.h>
#include <vector>
using namespace std;
#define INF 1<<30
struct line
{
	int b,e;
	int t;
}e[6666];
int minn[1000];
int T,n,m,w,s,en,t,cnt;
bool relax(int p)
{
	int sum=minn[e[p].b]+e[p].t;
	if(sum<minn[e[p].e])
	{
		minn[e[p].e]=sum;
		return true;
	}
	return false;
}
bool bellman()
{
	for(int i=1;i<=n;i++) minn[i]=INF;
	bool flag;
	for(int i=1;;i++)
	{
		if(i>n) return true;
		flag=false;
		for(int j=1;j<=cnt;j++)
		{
			if(relax(j)) flag=true;
		}
		if(!flag) return false;
	}
}
int main()
{
	cin>>T;
	while(T--)
	{
		cnt=0;
		cin>>n>>m>>w;
        for(int i=1;i<=m;i++)
		{
			cin>>s>>en>>t;
			cnt++;
			e[cnt].b=s;e[cnt].e=en;e[cnt].t=t;
			cnt++;
			e[cnt].b=en;e[cnt].e=s;e[cnt].t=t;

		}
		for(int i=1;i<=w;i++)
		{
			cin>>s>>en>>t;
			cnt++;
			e[cnt].b=s;e[cnt].e=en;e[cnt].t=-t;
		}
		if(bellman()) cout<<"YES"<<endl;
		else cout<<"NO"<<endl;
	}
	return 0;
}
