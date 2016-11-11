#include <bits/stdc++.h>
using namespace std;
int n,m;
int mp[233][233];
int mpp[233][233];
int sum;

char t;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
				cin>>t;
				if(t=='W') mp[i][j]=1;
				else mp[i][j]=-1;
		}
	}
	if(mp[n][m]==1)
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			mpp[i][j]=1;
	}
	else
	{
		for(int i=1;i<=n;i++)
			for(int j=1;j<=m;j++)
			mpp[i][j]=-1;
	}
    sum=1;
    int mm=m,nn=n;
    int ta=m,tn=n;
    int t;
    while(mm!=1&&nn!=1)
	{
		if(mpp[nn][mm]!=mp[nn][mm])
		{
			sum++;
			t=mp[nn][mm]-mpp[nn][mm];
			for(int i=1;i<=nn;i++)
				for(int j=1;j<=mm;j++)
				mpp[i][j]==t;
		}
        for(int i=nn-1;i>=1;i--)
		{
			if(mpp[i][mm]!=mp[i][mm])
			{
				sum++;
				t=mp[i][mm]-mpp[i][mm];
				for(int k=i;k>=1;k--)
				{
					for(int j=1;j<=mm;j++)
						mpp[k][j]+=t;
				}
			}
		}
		for(int i=mm-1;i>=1;i++)
		{
			if(mpp[])
		}
	}
	return 0;
}
