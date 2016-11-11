#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
double dp[2333][2333]={},n,p,sum;
int t;
int main()
{
	cin>>n>>p>>t;
	dp[0][0]=1;//
	for(int i=1;i<=t;i++)
		for(int j=n;j>=0;j--)
	{
		if(j==n)
			dp[i][j]=dp[i-1][j-1]*p+dp[i-1][j];
		else if(j==0)
			dp[i][j]=dp[i-1][j]*(1-p);
		else
			dp[i][j]=dp[i-1][j-1]*p+dp[i-1][j]*(1-p);
	}
	for(int i=1;i<=n;i++)
		sum+=i*dp[t][i];
	printf("%.7lf",sum);
	return 0;
}
