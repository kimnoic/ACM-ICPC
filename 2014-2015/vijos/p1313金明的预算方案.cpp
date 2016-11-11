#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int dp[50000]={};
int n,m;
int v[65],p[65],q[65];
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	cin>>n>>m;
	for(int i=1;i<=m;i++) cin>>v[i]>>p[i]>>q[i];
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++)
	{
		int t1=0,t2=0,k1=0,k2=0;
		if(q[i]==0)
		{
			for(int j=i+1;j<=m;j++)
			{
				if(q[j]==i)
				{
					t1=j;
					k1=1;
					break;
				}
			}
			for(int j=t1+1;j<=m;j++)
			{
				if(q[j]==i)
				{
					t2=j;
					k2=1;
					break;
				}
			}
			for(int j=n;j>=v[i];j--)
			{
				dp[j]=max(dp[j],dp[j-v[i]]+v[i]*p[i]);
				if(j-v[i]-v[t1]>=0&&k1==1)
				{
					dp[j]=max(dp[j],dp[j-v[i]-v[t1]]+v[i]*p[i]+v[t1]*p[t1]);
				}
				if(j-v[i]-v[t2]>=0&&k2==1)
				{
					dp[j]=max(dp[j],dp[j-v[i]-v[t2]]+v[i]*p[i]+v[t2]*p[t2]);
				}
				if(j-v[i]-v[t1]-v[t2]>=0&&k1==1&&k2==1)
				{
					dp[j]=max(dp[j],dp[j-v[i]-v[t1]-v[t2]]+v[i]*p[i]+v[t1]*p[t1]+v[t2]*p[t2]);
				}
			}
		}
	}
	cout<<dp[n];
	return 0;
}
