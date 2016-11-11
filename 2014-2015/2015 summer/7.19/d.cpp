#include <iostream>
#include <algorithm>
using namespace std;
int l,n,m;
long long a[555],b[555],c[555];
long long d[555*555];
int main()
{
	int _case=0;
	while(cin>>l)
	{
		cout<<"Case "<<++_case<<":"<<endl;
		cin>>n>>m;
		for(int i=1;i<=l;i++)
		{
			cin>>a[i];
		}
		for(int i=1;i<=n;i++)
		{
			cin>>b[i];
		}
		for(int i=1;i<=m;i++)
		{
			cin>>c[i];
		}
		int top=0;
		for(int i=1;i<=l;i++)
		{
			for(int j=1;j<=n;j++)
			{
				d[++top]=a[i]+b[j];
			}
		}
		sort(d+1,d+top+1);
		sort(c+1,c+m+1);
		int s;
		cin>>s;
		while(s--)
		{
			int ss;
			cin>>ss;
			int sumi=0,sumj=0;
			if(d[1]+c[1]>ss||c[m]+d[top]<ss)
			{
				cout<<"NO"<<endl;
				continue;
			}
			int flag=0;
            for(int i=1;i<=m;i++)
			{
				int p=ss-c[i];
				int l=1,r=top,mid=(r+l)/2;
				while(l<=r)
				{
					if(d[mid]>p)
					{
						r=mid-1;
						mid=(r+l)/2;
					}
					else if(d[mid]<p)
					{
						l=mid+1;
						mid=(r+l)/2;
					}
					else
					{
						flag=1;
						break;
					}
				}
			}
			if(flag) cout<<"YES"<<endl;
			else cout<<"NO"<<endl;
		}
	}
	return 0;
}
