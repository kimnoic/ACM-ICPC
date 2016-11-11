#include <iostream>
#include <algorithm>
using namespace std;
int m,n;
char t;
int mp[510][510];
int cnt=0;
int res=0;
int x1,x2,y1,y2;
bool flag=false;
int main()
{
	cin>>n>>m;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>t;
			if(t=='.') mp[i][j]=1;
			else cnt++;
		}
	}
	cin>>x1>>y1>>x2>>y2;
	if(mp[x2][y2]==0) cout<<"YES";
	else
	{
		if(x2-1>=1) res++;
		if(x2+1<=m) res++;
		if(y2-1>=1) res++;
		if(y2+1<=n) res++;
		if(res>=3) cout<<"YES";
			else cout<<"NO";
	}
	return 0;
}
