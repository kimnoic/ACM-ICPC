#include <iostream>
#include <algorithm>
#include <string.h>
#include <stdio.h>
using namespace std;
#define N 8888
int a[222];
int so[222][N];
int max(int a,int b)
{
	if(a>b) return a;
	else return b;
}
int n;
int sum=0;
int main()
{
	cin>>n;
	memset(so,0,sizeof(so));
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		sum+=a[i];
	}
	so[0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int k=n/2;k>=1;k--)
		for(int j=8000;j>=0;j--)
		{
			if(so[k-1][j]==1) so[k][j+a[i]]=1;
		}
	}
	for(int i=sum/2;i>=0;i--)
	{
		if(so[n/2][i])
		{
			if(i<=sum-i) cout<<i<<" "<<sum-i;
			else cout<<sum-i<<" "<<i;
			break;
		}
	}
	return 0;
}
//2477 2577
