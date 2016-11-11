#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
int num[1010];
int l[1010];
int n,m;
int tmp,pos,c,tol;
int minn,maxx;
bool flag=false;
int _case;
int main()
{
	while(cin>>n>>m)
	{
		memset(num,0,sizeof(num));
		minn=0;maxx=0,_case=0;
		for(int i=1;i<=m;i++)
		{
			cin>>tmp;
			num[tmp]=1;
		}
		for(int i=1;i<=n;i++)
		{
			if(num[i]==1)
			{
				minn=i;
				break;
			}
		}
		for(int i=n;i>=minn;i--)
		{
			if(num[i]==1)
			{
				maxx=i;
				break;
			}
		}
		if(minn<=1||maxx==n)
		{
			tol=n-maxx;
			if(tol==0) tol=minn-1;
			int i=1,j=1,k=1;
				for(i=1,j=i,k=i;i+j+k<=tol;i++)
				{
					for(j=i,k=j;i+j+k<=tol;j++)
					{
						for(k=j;i+j+k<=tol;k++)
						{
							if(i+j+k==tol&&i+j>k) _case++;
						}
						k=j+1;
					}
					j=i+1,k=j;
				}
			cout<<_case<<endl;
		}
		else
		{
			int a=min(minn-1,n-maxx);
			int b=max(minn-1,n-maxx);
			for(int i=1;i<b;i++)
			{
				if(i+a>b-i&&b>a&&a+b-i>i) _case++;
			}
			cout<<_case<<endl;
		}
	}
	return 0;
}
