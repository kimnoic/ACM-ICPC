#include <iostream>
#include <string.h>

using namespace std;
int c[233];
int w[233];
int dp[233][15010];
int main()
{
	dp[0][7500]=1;
	int n,m;
	cin>>n>>m;
	memset(dp,0,sizeof(dp));
	for(int i=1;i<=n;i++) cin>>c[i];
	for(int i=1;i<=m;i++) cin>>w[i];
	dp[0][7500]=1;
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=15000;j++)
		{
			if(dp[i-1][j])
			{
				for(int k=1;k<=n;k++)
				{
					dp[i][j+c[k]*w[i]]+=dp[i-1][j];
				}
			}
		}
	}
	cout<<dp[m][7500];
	return 0;
}
