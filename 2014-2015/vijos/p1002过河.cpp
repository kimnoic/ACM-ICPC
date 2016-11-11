#include <iostream>
#include <algorithm>
#include <string.h>
using namespace std;
#define N 2520
#define Max 252000
#define MMM 1000000
int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}
int a[252000]={};
int dp[252000]={};
int b[101];
int sum=0;
int main()
{
	long long l;
	cin>>l;
	int s,t,m;
	cin>>s>>t>>m;
	for(int i=1;i<=m;i++)
	{
		cin>>b[i];
	}
	sort(b+1,b+m+1);
	b[0]=0;
	for(int i=1;i<=m;i++)
	{
		a[(b[i]-b[i-1])%N]=1;
	}
	int k=m*2520;
	//for(int i=1;i<=k;i++) dp[i]=MMM;
	for(int i=s=0;i<=100;i++)
	{

		for(int j=s;j<=t;j++)
		{
			int t=MMM;
			cout<<dp[i+j]<<endl;
			t=min(t,a[i+j]+dp[i]);
			dp[i+j]+=t;
		}

	}
	cout<<dp[k];
	return 0;
}














