#include <iostream>
#include <string.h>
using namespace std;
int bx,by,cx,cy;
int table[25][25]={};
int dx[9]={0,-2,-1,1,2,2,1,-1,-2};
int dy[9]={0,1,2,2,1,-1,-2,-2,-1};
int main()
{
	cin>>bx>>by>>cx>>cy;
	memset(table,0,sizeof(table));
	table[cy][cx]=0;
	for(int i=1;i<=8;i++)
	{
		if(cx+dx[i]>=0&&cy+dy[i]>=0)
			{
				table[cx+dx[i]][cy+dy[i]]=-1;
			}
	}
	table[0][0]=1;
	table[cx][cy]=-1;
	for(int i=0;i<=bx;i++)
		for(int j=0;j<=by;j++)
	{
		if(table[i][j]!=-1)
		{
			if(table[i+1][j]!=-1) table[i+1][j]+=table[i][j];
			if(table[i][j+1]!=-1) table[i][j+1]+=table[i][j];
		}
	}
	cout<<table[bx][by];
	return 0;
}
