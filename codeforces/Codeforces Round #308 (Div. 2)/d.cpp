#include <bits/stdc++.h>
using namespace std;
#define Max 2333
int x[2333];
int y[2333];
int gcd(int a,int b)
{
	if(b==0) return a;
	else return gcd(b,a%b);
}
int mp[233][233]={};
int main()
{
	int n;
	cin>>n;
	int aa,bb;
	for(int i=1;i<=n;i++)
	{
		cin>>aa>>bb;
		aa+=100;
		bb+=100;
		mp[aa][bb]=1;
	}
	int top=0;
	for(int i=0;i<=200;i++)
	{
		for(int j=0;j<=200;j++)
		{
			if(mp[i][j])
			{
				x[++top]=i;
				y[top]=j;
			}
		}
	}
	n=top;
	long long sum=0;
	for(int i=1;i<=n;i++)
	{
        for(int j=1;j<=n;j++)
		{
			if(i!=j)
			{
				int u=-1;
				int xa=x[i],ya=y[i];
				int xb=x[j],yb=y[j];
				int xx=xa-xb;
				int yy=ya-yb;
				int g;
				if(xx==0||yy==0)
				{
					if(xx==0)
					{
						yy=1;
					}
					else xx=1;
				}
				else {g=gcd(xx,yy);
				xx/=g;
				yy/=g;}
				int tx=xa;
				int ty=ya;
				while(tx<=200&&ty<=200&&tx>=0&&ty>=0)
				{
					tx+=xx;
					ty+=yy;
					if(!(tx<=200&&ty<=200&&tx>=0&&ty>=0)) break;
					if(mp[tx][ty]) u++;
				}
				tx=xa;
				ty=ya;
				while(tx<=200&&ty<=200&&tx>=0&&ty>=0)
				{
					tx-=xx;
					ty-=yy;
					if(!(tx<=200&&ty<=200&&tx>=0&&ty>=0)) break;
					if(mp[tx][ty]) u++;
				}
				sum+=(n-2-u);
			}
		}
	}
	cout<<sum/6;
	return 0;
}
