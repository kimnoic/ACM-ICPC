#include <bits/stdc++.h>
using namespace std;
int a[3010];
int n;

int main()
{
	cin>>n;
	for(int i=0;i<n;i++)
		 cin>>a[i];
	sort(a,a+n);
	int res=0;
	for(int i=1;i<n;i++)
	{
		if(a[i]==a[i-1])
		{
			a[i]++;
			sort(a+i,a+n);
			res++;
		}
	}
	cout<<res;
	return 0;
}
