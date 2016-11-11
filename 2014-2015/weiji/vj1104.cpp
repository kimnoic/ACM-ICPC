#include <iostream>
#include <algorithm>
#include <stdio.h>
#include <string.h>
using namespace std;
int t,m;
int dp[1010];
int yt[110],yw[110];
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	cin>>t>>m;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=m;i++) cin>>yt[i]>>yw[i];
	for(int i=1;i<=m;i++)
		for(int j=t;j>=yt[i];j--)
	{
		dp[j]=max(dp[j],dp[j-yt[i]]+yw[i]);
	}
	cout<<dp[t];
	return 0;
}
