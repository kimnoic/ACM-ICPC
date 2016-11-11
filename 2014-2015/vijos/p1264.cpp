#include <iostream>
#include <string.h>

using namespace std;
int _case ;
int n,m;
long long le[600];
long long ri[600];
int dp[600][600];
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int main()
{
	cin>>_case;
	while(_case--)
	{
		memset(dp,0,sizeof(dp));
		cin>>n;
		for(int i=1;i<=n;i++) cin>>le[i];
		cin>>m;
		for(int i=1;i<=m;i++) cin>>ri[i];
		for(int i=1;i<=n;i++)
		{
			int t=0;
			for(int j=1;j<=m;j++)
			{
				dp[i][j]=dp[i-1][j];
				if(le[i]>ri[j]) t=max(t,dp[i-1][j]);
				if(le[i]==ri[j]) dp[i][j]=t+1;
			}
		}
		int ans=0;
		for(int i=1;i<=m;i++)
			ans=max(ans,dp[n][i]);
		cout<<ans;
	}
	return 0;
}
