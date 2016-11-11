#include <bits/stdc++.h>
#define N 233
using namespace std;
char mp[N][N];
int n,m;
int al[N];
int main()
{
	scanf("%d%d",&n,&m);
	int sum=0;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>mp[i][j];
		}
	}
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<m;j++)
		{
			memset(al,0,sizeof(al));
			int a=mp[i][j]-'a'+1;
			al[a]=1;
			a=mp[i+1][j]-'a'+1;
			al[a]=1;
			a=mp[i][j+1]-'a'+1;
			al[a]=1;
			a=mp[i+1][j+1]-'a'+1;
			al[a]=1;
			if(al[1]==1&&al[3]==1&&al[5]==1&&al[6]==1) sum++;
		}
	}
	cout<<sum;
	return 0;
}
