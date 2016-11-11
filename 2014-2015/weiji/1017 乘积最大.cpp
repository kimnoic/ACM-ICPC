#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
int map[51][51];
int main()
{
	int n,m,i,j,k,t;
	char str[10001];
	cin>>n>>m;
	cin>>str;
	for(i=0;i<n;i++)
	{
		int mm;
		mm=0;
		for(j=i;j<n;j++)
		{
			mm=mm*10+str[j]-'0';
			map[i][j]=mm;
		}
	}
	int dp[51][10];
	memset(dp,0,sizeof(dp));
	for(j=0;j<n;j++)
		dp[j][0]=map[0][j];
	for(j=0;j<n;j++)
	{
		for(k=1;k<=m;k++)
		{
			for(t=0;t<j;t++)
			{
				dp[j][k]=max(dp[t][k-1]*map[t+1][j],dp[j][k]);
			}
		}
	}
	cout<<dp[n-1][m]<<endl;
	return 0;
}
