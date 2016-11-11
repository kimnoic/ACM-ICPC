#include <bits/stdc++.h>
using namespace std;
#define Max 2333
int a[Max],b[Max],c[Max];
int n,t;

int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		a[i]=t;
	}
	int p=0;
	int maxx;
	while(p!=n)
	{
		maxx=0;
		int t=0;
		for(int i=1;i<=n;i++)
		{
			if(!b[i]&&maxx<a[i])
			{
				maxx=a[i];
			}
		}
		for(int i=1;i<=n;i++)
		{
			if(a[i]==maxx)
			{
				b[i]=1;
				t++;p++;
			}
		}
		c[maxx]=p-t+1;
	}
	for(int i=1;i<=n;i++)
	{
		cout<<c[a[i]]<<" ";
	}
	return 0;
}
