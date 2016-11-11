#include <iostream>
#include <string.h>
#define N 1010
int x[N];
int a[21]={};
int b[21]={};
using namespace std;
int n,m,k;
int main()
{
	cin>>n>>m>>k;
	int num=0;
	for(int i=1;i<=m;i++) cin>>x[i];
	long long tt;
	cin>>tt;
	for(int i=1;i<=m;i++)
	{
		memset(a,0,sizeof(a));
		memset(b,0,sizeof(b));
		long long y=tt;
		for(int j=1;j<=20;j++)
		{
			a[j]=y%2;
			y/=2;
			b[j]=x[i]%2;
			x[i]/=2;
		}
		int ans=0;
		for(int j=1;j<=20;j++)
		{
			if(a[j]!=b[j]) ans++;
		}
		if(ans<=k) num++;
	}
	cout<<num;
	return 0;
}
