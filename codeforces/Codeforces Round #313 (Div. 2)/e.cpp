#include <bits/stdc++.h>
using namespace std;
#define Max 10001
int mp[Max][Max];
int w,h,n;
int main()
{
	cin>>w>>h>>n;
	for(int i=1;i<=n;i++)
	{
		int a,b;
		cin>>a>>b;
		mp[a][b]=-1;
	}
	mp[1][1]=1;
	for(int j=1;j<=h;j++)
	{
		for(int i=1;i<=w;i++)
		{
			if(mp[i][j]==-1) continue;
			if(mp[i-1][j]!=-1)
			{
				mp[i][j]+=mp[i-1][j];
			}
			if(mp[i][j-1]!=-1)
			{
				mp[i][j]+=mp[i][j-1];
			}
			//cout<<i<<" "<<j<<" "<<mp[i][j]<<endl;
		}
	}
	cout<<mp[w][h];
	return 0;
}
