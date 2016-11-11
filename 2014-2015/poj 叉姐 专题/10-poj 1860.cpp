#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <map>
#include <vector>
#include <set>
#include <math.h>
#include <string.h>
#include <stdlib.h>
using namespace std;
struct p
{
	int a,b;
	double r,c;
}e[233];

int t,n,s,cnt;
double ans;double minn[233];
int be,en;
double r1,c1,r2,c2;
bool relax(int q)
{
	double sum=(minn[e[q].a]-e[q].c)*e[q].r;
	if(sum>minn[e[q].b])
	{
		minn[e[q].b]=sum;
		return true;
	}
	return false;
}
bool bellford()
{
	bool flag;
	for(int i=1;i<=n;i++) minn[i]=0;
	minn[s]=ans;
	for(int i=1;i<n;i++)
	{
		flag=false;
		for(int j=1;j<=cnt;j++)
		{
			if(relax(j)) flag=true;
		}
		if(minn[s]>ans) return true;
		if(!flag) {return false;}
	}
	for(int i=1;i<=cnt;i++)
	{
		if(relax(i)) return true;
	}
	return false;
}
int main()
{
	cin>>n>>t>>s>>ans;
	cnt=0;
	for(int i=1;i<=t;i++)
	{
		cin>>be>>en>>r1>>c1>>r2>>c2;
		cnt++;
		e[cnt].a=be;e[cnt].b=en;e[cnt].r=r1;e[cnt].c=c1;
		cnt++;
		e[cnt].a=en;e[cnt].b=be;e[cnt].r=r2;e[cnt].c=c2;
	}

	bool k=bellford();
	if(k) cout<<"YES";
	else cout<<"NO";
	return 0;
}
