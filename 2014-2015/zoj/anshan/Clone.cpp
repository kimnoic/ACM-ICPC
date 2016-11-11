#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
using namespace std;
#define MOD 1000000007
#define N 2010
int t;
int n;
int a[N];
int f[N][N]={};
int min(int a,int b)
{
	if(a<b) return a;
	else return b;
}
int main()
{
	cin>>t;
	while(t--)
	{
		cin>>n;	int sum=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
			sum+=a[i];
		}
		sum/=2;
		memset(f,0,sizeof(f));
		for(int i=0;i<=n;i++) f[i][0]=1;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=sum;j++)
			{
				int minn=min(a[i],j);
				for(int k=0;k<=minn;k++)
				{
					f[i][j]=(f[i][j]+f[i-1][j-k])%MOD;
				}
			}
		}
		cout<<f[n][sum]<<endl;
	}
	return 0;
}
