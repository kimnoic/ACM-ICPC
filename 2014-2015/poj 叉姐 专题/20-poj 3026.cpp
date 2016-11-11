#include <string.h>
#include <iostream>
#include <string>
#include <stdio.h>
using namespace std;

const int inf=2501;

char map[51][51];
int node[51][51];
int col,row;
int num;
int dist[102][102];
int edge[102][102];

class move
{
 public:
	int row,col;
}mov[4]={{0,-1},{0,1},{-1,0},{1,0}};

void bfs(int i,int j)
{
	bool vist[51][51];
	int que_x[2500],que_y[2500];
	int head=0,tail=0;



	memset(dist,0,sizeof(dist));
	memset(vist,false,sizeof(vist));
	vist[i][j]=true;
	que_x[tail]=i;
	que_y[tail++]=j;

	while(head<tail)
	{
		int x=que_x[head];
		int y=que_y[head++];
		if(node[x][y])
			edge[ node[i][j] ][ node[x][y] ] = dist[x][y];
		for(int k=0;k<4;k++)
		{
			int mx=x+mov[k].row;
			int my=y+mov[k].col;
			if(mx>=1 && mx<= row && my>=1 && my<=col)
				if(!vist[mx][my] && map[mx][my]!='#')
				{
					que_x[tail]=mx;
					que_y[tail++]=my;
					vist[mx][my]=true;
					dist[mx][my]=dist[x][y]+1;
				}
		}
	}
	return;
}

int prim(void)
{
	int s=1;
	int m=1;
	bool u[102];
	u[s]=true;

	int min_w;
	int prim_w=0;
	int point;
	int low_dis[102];

	for(int i=1;i<=num;i++)
	{
		low_dis[i]=inf;
		u[i]=false;
	}

	while(true)
	{
		if(m==num)
			break;

		min_w=inf;
		for(int i=2;i<=num;i++)
		{
			if(!u[i] && low_dis[i]>edge[s][i])
				low_dis[i] = edge[s][i];
			if(!u[i] && min_w>low_dis[i])
			{
				min_w=low_dis[i];
				point=i;
			}
		}
		s=point;
		u[s]=true;
		prim_w+=min_w;
		m++;
	}
	return prim_w;
}

int main()
{
	int test;
	cin>>test;
	while(test--)
	{

		memset(node,0,sizeof(node));
		num=0;


		cin>>col>>row;
		char temp[51];
		gets(temp);
		for(int i=1;i<=row;i++)
		{
			gets(map[i]);
			for(int j=1;j<=col;j++)
				if(map[i][j]=='A'||map[i][j]=='S')
					node[i][j]=++num;
		}

		for(int i=1;i<=row;i++)
			for(int j=1;j<=col;j++)
				if(node[i][j])
					bfs(i,j);

		cout<<prim()<<endl;
	}
	return 0;
}
