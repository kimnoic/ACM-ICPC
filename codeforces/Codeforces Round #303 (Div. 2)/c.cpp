#include <bits/stdc++.h>
using namespace std;
int n;
long long x[100010],h[100010];
int re[100010];
int main()
{
	cin>>n;
	x[0]=-10000000000;
	int flag=1;
	int cnt=2;
	if(n==1)
	{
		cout<<"1"<<endl;
		return 0;
	}
	for(int i=1;i<=n;i++) cin>>x[i]>>h[i];
	re[1]=1;
	for(int i=2;i<n;i++)
	{
		if(!re[i])
		{
			if(h[i]==x[i]-x[i-1])
			{
				if(!re[i-1]) {cnt++;re[i]=1;continue;}
			}
			else if(h[i]<x[i]-x[i-1])
			{
				cnt++;
				re[i]=1;
				continue;
			}
			if(h[i]==x[i+1]-x[i])
			{
				cnt++;
				re[i+1]=1;
				continue;
			}
			else if(h[i]<x[i+1]-x[i])
			{
				cnt++;
				x[i]+=h[i];
				re[i]=1;
				continue;
			}
		}
		re[i]=1;
	}
	if(re[n]) cnt--;
	cout<<cnt;
	return 0;
}
