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
	int _case=0;
	cin>>T;
	while(T--)
	{
		cin>>n;
		cnt_a=0;
		cnt_b=0;
		memset(c,0,sizeof(c));
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
		cout<<"Case #"<<++_case<<":"<<endl;
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
						if(b[j].x1<=minn) minn=b[j].x1;
						if(b[j].x2>=maxx) maxx=b[j].x2;
					}
				}
				cnt++;
				c[cnt].y=yy;
				c[cnt].x1=minn;
				c[cnt].x2=maxx;
			}
		}
		int cntd=0;
		memset(vis,0,sizeof(vis));
		for(int i=1;i<=cnt_a;i++)
		{
			if(!vis[i])
			{
				vis[i]=1;
				int xx=a[i].x,minn=a[i].y1,maxx=a[i].y2;
				for(int j=1;j<=cnt_a;j++)
				{
					if(!vis[j]&&((a[j].y1<=maxx&&a[j].y1>=minn)||(a[j].y2>=minn&&a[j].y2<=maxx))&&a[j].x==xx)
					{
						vis[j]=1;
						if(a[j].y1<=minn) minn=a[j].x1;
						if(a[j].y2>=maxx) maxx=a[j].x2;
					}
				}
				cntd++;
				d[cntd].x=xx;
				d[cntd].y1=minn;
				d[cntd].y2=maxx;
			}
		}
		int sum=0;
		for(int i=1;i<cnt;i++)
		{
			for(int j=i+1;j<=cnt;j++)
			{
				if(c[i].x2<c[j].x1||c[i].x1>c[j].x1||c[i].y==c[j].y) continue;
				for(int k=1;k<cntd;k++)
				{
					for(int q=k+1;q<=cntd;q++)
					{
						if(d[k].y1>=d[q].y2||d[k].y2<=d[q].y1||d[k].x==d[q].x) continue;
						x1=max(c[i].x1,c[j].x1);
						x2=min(c[i].x2,c[j].x2);
						if(x1==x2) continue;
                        if(x1>=max(d[k].x,d[q].x)) continue;
                        if(x2<=min(d[k].x,d[q].x)) continue;
                        yy1=max(d[k].y1,d[q].y1);
						yy2=min(d[k].y2,d[q].y2);
						if(yy1==yy2) continue;
                        if(yy1>=max(c[i].y,c[j].y)) continue;
                        if(yy2<=min(c[i].y,c[j].y)) continue;
                        sum++;
					}
				}
			}
		}
		cout<<sum<<endl;
	}
	return 0;
}
/*
10
10
1 1 5 1
1 2 5 2
1 3 5 3
1 4 5 4
1 5 5 5
1 1 1 5
2 1 2 5
3 1 3 5
4 1 4 5
5 1 5 5
*/
