#include <bits/stdc++.h>
using namespace std;
int n;
#define Max 1000010
int a[Max];
int t;
int main()
{
	cin>>n;
	int flag=1;
	for(int i=1;i<=n;i++)
	{
		cin>>t;
		if(t==1)
		{
			flag=0;
		}
	}
	if(!flag) cout<<"-1";
	else cout<<"1";
	return 0;
}
