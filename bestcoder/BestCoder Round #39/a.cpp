#include <iostream>
#include <string.h>
using namespace std;
int a[110];
int n,k;
int main()
{
	while(cin>>n)
	{
		int t;
		int c=0;
		memset(a,0,sizeof(a));
		for(int i=1;i<=n;i++)
		{
			cin>>t;
			if(a[t]==0) c++;
			a[t]++;
		}
		cin>>k;
		int y=n-c;
		int u=k-y;
		if(u>0) cout<<c-u<<endl;
		else cout<<c<<endl;
	}
	return 0;
}
