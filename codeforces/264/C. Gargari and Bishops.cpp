#include <iostream>
using namespace std;
#define N 2010
long long table[N][N];
long long n;
long long zx[2*N]={};
long long yx[2*N]={};
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
			cin>>table[i][j];
	}
	int t1=1;
	for(int i=1;i<=n;i++)
	{
		int x=i;
		int y=1;
		for(int j=1;j<=t1;j++)
		{
			zx[i]+=table[x][y];
			x--;y++;
		}
		t1++;
	}
	t1=n-1;
	for(int i=n+1;i<=2*n-1;i++)
	{
		int x=n;
		int y=i%n+1;t1--;
		for(int j=1;j<=t1;j++)
		{
			zx[i]+=table[x][y];
			x--;y++;
		}
		t1--;
	}
	t1=1;
	for(int i=1;i<=n;i++)
	{
		int x=i;
		int y=n;
		for(int j=1;j<=t1;j++)
		{
			yx[i]+=table[x][y];
			x--;y--;
		}
		t1++;
	}
	t1=n-1;
	for(int i=n+1;i<=2*n-1;i++)
	{
		int x=n;
		int y=2*n-i;
		for(int j=1;j<=t1;j++)
		{
			yx[i]+=table[x][y];
			x--;y--;
		}
	}
	long long sum1=0;
	long long sum2=0;
	long long x1,x2,y1,y2;
	for(int i=1;i<=n;i++)
	{
		for(int j=(i+1)%2;j<=n;j+=2)
		{
			if(sum1<zx[i+j-1]+yx[i+n-j]-table[i][j])
			{
				sum1=zx[i+j-1]+yx[i+n-j]-table[i][j];
				x1=i;
				y1=j;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i%2;j<=n;j+=2)
		{
			if(sum2<zx[i+j-1]+yx[i+n-j]-table[i][j])
			{
				sum2=zx[i+j-1]+yx[i+n-j]-table[i][j];
				x2=i;
				y2=j;
			}
		}
	}
	cout<<sum1+sum2<<endl;
	cout<<x2<<" "<<y2<<" "<<x1<<" "<<y1;
	return 0;
}
