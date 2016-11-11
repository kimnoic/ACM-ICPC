#include <iostream>
#include <string.h>
using namespace std;
int a[10010],b[10010];
int n,tmp;
int main()
{
	while(cin>>n)
	{
		memset(b,0,sizeof(b));
		long long ans=0;
		for(int i=1;i<=n;i++)
		{
			cin>>a[i];
		}
		for(int i=n;i>=1;i--)
		{
			b[a[i]]=i;
			tmp=10001;
			for(int j=2;j*a[i]<=10000;j++)
			{
				if(b[j*a[i]]!=0&&b[j*a[i]]<tmp)
					tmp=b[j*a[i]];
			}
			if(tmp!=10001) ans+=tmp;
		}
		cout<<ans<<endl;
	}
	return 0;
}
