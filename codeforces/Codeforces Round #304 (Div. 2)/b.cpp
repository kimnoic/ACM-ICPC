#include <bits/stdc++.h>
using namespace std;
int a[3010];
int n;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		 a[i]=1;
	sort(a,a+n);
	int res=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]<=a[i-1])
		{
			a[i]+=a[i]-a[i-1];
			if(a[i]==a[i-1]) {a[i]++;res++;}
			res+=a[i]-a[i-1];
		}
	}
	cout<<res;
	return 0;
}
