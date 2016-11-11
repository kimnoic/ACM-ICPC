#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <queue>
#include <stack>
#include <map>
#include <set>
#include <math.h>
#include <vector>
#include <stdlib.h>
using namespace std;
#define INF 1<<30
struct edge
{
	int x,y,x1,x2,y1,y2;
	int k1,k2;
}a[2333],b[2333],c[2333],d[2333];
int T,n,x1,x2,yy1,yy2,cnt_a,cnt_b;
int vis[2333];
int main()
{
	cin>>T;
	while(T--)
	{
		cin>>n;
		cnt_a=0;
		cnt_b=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=n;i++)
		{
			cin>>x1>>yy1>>x2>>yy2;
			if(x1==x2)
			{
				cnt_a++;
				a[cnt_a].x=x1;
				a[cnt_a].y1=min(yy1,yy2);
				a[cnt_a].y2=max(yy1,yy2);
			}
			else
			{
				cnt_b++;
				b[cnt_b].y=yy1;
				b[cnt_b].x1=min(x1,x2);
				b[cnt_b].x2=max(x1,x2);
			}
		}
		int cnt=0;
        for(int i=1;i<=cnt_b;i++)
		{
			if(!vis[i])
			{
				vis[i]=1;
				int yy=b[i].y,minn=b[i].x1,maxx=b[i].x2;
				for(int j=1;j<=cnt_a;j++)
				{
					if(!vis[j]&&((b[j].x2<=maxx&&b[j].x1>=minn)||(b[j].x1>=minn&&b[j].x1<=maxx))&&b[j].y==yy)
					{
						vis[j]=1;
						if(x1<=minn) minn=x1;
						if(x2>=maxx) maxx=x2;
					}
				}
				cnt++;
				c[cnt].y=yy;
				c[cnt].x1=minn;
				c[cnt].x2=maxx;
			}
		}
		for(int i=1;i<=cnt;i++)
		{
			c[i].k1=0;
			c[i].k2=0;
		}
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=cnt;i++)
		{
			cout<<cnt<<endl;
			for(int j=1;j<=cnt_a;j++)
			{
				if(!vis[i]&&c[i].y>=a[j].y1&&c[i].y<=a[j].y2&&a[j].x>=c[i].x1&&a[j].x<=c[i].x2)
				{
					vis[i]=1;
					if(c[i].k1==0&&c[i].k2==0)
					{
						cnt++;
						cout<<cnt<<endl;
						c[cnt].x1=c[i].x1;
						c[cnt].x2=a[j].x;
						c[cnt].k1=a[j].x;
						c[cnt].k2=0;
						c[cnt].y=c[i].y;
						cnt++;
						c[cnt].x1=a[j].x;
						c[cnt].x2=c[i].x2;
						c[cnt].y=c[i].y;
						c[cnt].k1=a[j].x;
						c[cnt].k2=0;
					}
					else if(c[i].k1!=0&&c[i].k2!=0&&c[i].k1<a[j].x&&c[i].k2>a[j].x)
					{
						cnt++;
						c[cnt].x1=c[i].k1;
						c[cnt].x2=a[j].x;
						c[cnt].k1=c[i].x1;
						c[cnt].k2=a[j].x;
						c[cnt].y=c[i].y;
						cnt++;
						c[cnt].x1=a[j].x;
						c[cnt].x2=c[i].k2;
						c[cnt].k1=a[j].x;
						c[cnt].k2=c[i].x2;
						c[cnt].y=c[i].y;
					}
					else if(c[i].k1!=0&&c[i].k1!=a[j].x)
					{
						if(a[j].x<c[i].k1)
						{
							cnt++;
							c[cnt].x1=a[j].x;
							c[cnt].x2=c[i].k1;
							c[cnt].k1=a[j].x;
							c[cnt].k2=c[i].k1;
							c[cnt].y=c[i].y;
							if(a[j].x==c[i].x1) continue;
							cnt++;
							c[cnt].x1=c[i].x1;
							c[cnt].x2=a[j].x;
							c[cnt].k1=a[j].x;
							c[cnt].y=c[i].y;
						}
						else if(a[j].x>c[i].k1)
						{
							cnt++;
							cout<<"asdf ";
							c[cnt].x1=c[i].k1;
							c[cnt].x2=a[j].x;
							c[cnt].k1=c[i].k1;
							c[cnt].k2=a[j].x;
							c[cnt].y=c[i].y;
							if(a[j].x==c[i].x2) continue;
							cnt++;
							c[cnt].x1=a[j].x;
							c[cnt].x2=c[i].x2;
							c[cnt].k1=a[j].x;
							c[cnt].y=c[i].y;
						}
					}
				}
			}
		//cout<<cnt<<" ";
		}
		for(int i=1;i<=cnt;i++)
		{
			cout<<c[i].k1<<" "<<c[i].k2<<" "<<c[i].y<<endl;
		}
		int sum=0;
		for(int i=1;i<cnt;i++)
		{
			for(int j=i+1;j<=cnt;j++)
			{
				if(c[i].k1==c[j].k1&&c[i].k1!=c[i].k2&&c[i].k2==c[j].k2&&c[i].k1!=0&&c[i].k2!=0&&c[i].y!=c[j].y)
				{
					sum++;
					//cout<<c[i].k1<<" "<<c[i].k2<<endl;
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
