#include <iostream>
#include <string.h>
using namespace std;
int a[11][11111]={};
int n,m;
void cal()
{
	for(int i=n;i>0;i--)
	{
		for(int j=m;j>0;j--)
		{
			a[i-1][j]+=a[i][j];
			a[i][j-1]+=a[i][j];
		}
	}
	cout<<endl;
}
int main()
{
	while(cin>>n>>m)
	{
		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=m;j++) a[i][j]=0;
		}
		a[n][m]=1;
		cal();
		for(int i=0;i<=n;i++)
	{
		for(int j=0;j<=m;j++)
		{
			cout<<a[i][j]<<" ";
		}
		cout<<endl;
	}
	}
	return 0;
}
