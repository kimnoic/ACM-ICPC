#include <bits/stdc++.h>
using namespace std;
#define Max 1000010
int a[100010];
int num[1000010];
int c[1000010];
int d[1000010];
int main()
{
	int n;
    cin>>n;
    int t;
    for(int i=1;i<Max;i++) c[i]=Max;
    for(int i=1;i<Max;i++) d[i]=-Max;
    for(int i=1;i<=n;i++)
	{
		cin>>t;
		c[t]=min(c[t],i);
		d[t]=max(d[t],i);
		num[t]++;
	}
	int maxx=0;
	for(int i=1;i<Max;i++)
	{
		maxx=max(maxx,num[i]);
	}
	int ans=Max;
	int pos;
	for(int i=1;i<Max;i++)
	{
		if(num[i]==maxx&&d[i]-c[i]<ans)
		{
			ans=d[i]-c[i];
			pos=i;
		}
	}
	cout<<c[pos]<<" "<<d[pos];
	return 0;
}
