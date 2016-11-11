#include <iostream>
#include <string.h>
#include <math.h>
#include <algorithm>
using namespace std;
int n,d;
struct point
{
	int x,y;
	double xx;
}p[1010];
int flag;
bool compare(point a,point b)
{
	return a.xx<b.xx;
}
int vis[1010];
int main()
{
	int _case=0;
	while(cin>>n>>d)
	{
		flag=0;
		if(n==0&&d==0) break;

		for(int i=1;i<=n;i++)
		{
			cin>>p[i].x>>p[i].y;
			if(p[i].y>d) flag=1;
			else
			{
				p[i].xx=p[i].x+sqrt(d*d-p[i].y*p[i].y);
			}
		}
		if(flag==1)
		{
			cout<<"Case "<<++_case<<": ";
			cout<<"-1"<<endl;
			continue;
		}
		sort(p+1,p+n+1,compare);
		int cnt=0;
		memset(vis,0,sizeof(vis));
		//cout<<"asdf";
		for(int i=1;i<=n;i++)
		{
			if(!vis[i])
			{
				cnt++;
				for(int j=1;i+j<=n;j++)
				{
					if(((p[i].xx-p[i+j].x)*(p[i].xx-p[i+j].x)+p[i+j].y*p[i+j].y)<=d*d)
					{
						vis[i+j]=1;
					}
					else break;
				}
			}
		}
		cout<<"Case "<<++_case<<": ";
		cout<<cnt<<endl;
	}
	return 0;
}
