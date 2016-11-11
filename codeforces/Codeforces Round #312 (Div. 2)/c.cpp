#include <bits/stdc++.h>
using namespace std;
int n;
#define Max 100100
int a[Max];
int b[Max];
int c[Max];
int main()
{

	cin>>n;
	int res=0;
	for(int i=1;i<=n;i++)
	{
		cin>>a[i];
		if(a[i]>res) res=a[i];
	}
	memset(b,0,sizeof(b));
	memset(c,0,sizeof(c));
	for(int i=1;i<=n;i++)
	{
		int p=a[i];
		int cnt=0;
		while(p>=1)
		{
			b[p]++;
			c[p]+=cnt;
			cnt++;
			p/=2;
		}
	}
    int maxx=c[1];
	for(int i=2;i<=res;i++)
	{
        if(b[i]==n)
		{
			if(c[i]<maxx)
			{
				maxx=c[i];
			}
		}
		else if(i%2==0&&b[i/2]==n)
        {
            c[i]=c[i/2]-b[i]+n-b[i];
            b[i]=n;
            maxx=min(maxx,c[i]);
        }
	}
	cout<<maxx;
	return 0;
}
