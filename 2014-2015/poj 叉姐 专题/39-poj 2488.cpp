#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <math.h>
#include <stdlib.h>
#include <vector>
#include <queue>
#include <stack>
#include <map>
#include <set>
using namespace std;
int xx[9]={0,-2,-2,-1,-1,1,1,2,2};
int yy[9]={0,-1,1,-2,2,-2,2,-1,1};
int mp[50][50];
int T,m,n,flag;
struct path
{
	int x,y;
}p[233];
bool check(int x,int y)
{
	if(x>0&&y>0&&x<=n&&y<=m&&mp[x][y]==0) return true;
	return false;
}
void dfs(int x,int y,int step)
{
	p[step].x=x;
	p[step].y=y;
	//cout<<x<<" "<<y<<" "<<step<<endl;
	if(step==m*n)
	{
		flag=1;
		return ;
	}
	for(int i=1;i<=8;i++)
	{
		if(check(x+xx[i],y+yy[i]))
		{
			mp[x+xx[i]][y+yy[i]]=1;
			dfs(x+xx[i],y+yy[i],step+1);
			if(flag) return ;
			mp[x+xx[i]][y+yy[i]]=0;
		}
	}
}

int main()
{
	cin>>T;
	int _case=0;
	while(T--)
	{
		cout<<"Scenario #"<<++_case<<":"<<endl;
		cin>>m>>n;
		flag=0;
		memset(mp,0,sizeof(mp));
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				memset(mp,0,sizeof(mp));
				mp[i][j]=1;
				dfs(i,j,1);
				if(flag) break;
				mp[i][j]=0;
			}
			if(flag) break;
		}
		if(!flag) cout<<"impossible"<<endl<<endl;
		else
		{
			for(int i=1;i<=m*n;i++)
				cout<<(char)(p[i].x+'A'-1)<<p[i].y;
			cout<<endl<<endl;
		}
	}
	return 0;
}
