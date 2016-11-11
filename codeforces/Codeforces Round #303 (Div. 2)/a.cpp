#include <bits/stdc++.h>
using namespace std;
int mp[110][110];
int n;
int res[110];
int top=0;
int main()
{
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int flag=0;
		for(int j=1;j<=n;j++)
		{
			cin>>mp[i][j];
			if(mp[i][j]==1||mp[i][j]==3)
			{
				flag=1;
			}
		}
		if(!flag)
		{
			res[++top]=i;
		}
	}
	cout<<top<<endl;
	for(int i=1;i<=top;i++)
	{cout<<res[i];if(i!=n)cout<<" ";}
	return 0;
}
