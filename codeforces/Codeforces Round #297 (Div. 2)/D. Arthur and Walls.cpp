#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <set>
#include <queue>
#include <map>
#include <stack>
#include <vector>
#include <stdlib.h>
#include <math.h>
using namespace std;
const int N= 2020;
char mapp[N][N];
int r,c;
int dx[5]={0,1,0,-1,0}; //前一个和后一个dx，dy坐标呈90度
int dy[5]={1,0,-1,0,1};
int f(int a,int b)
{
    return a? a:b;
}
void dfs(int x,int y)
{
    if(mapp[x][y]!='*') return;
    for(int i=0;i<4;i++)
    {
        int x1=x+dx[i];
        int y1=y+dy[i];
        int x2=x+dx[i+1];
        int y2=y+dy[i+1];
        int x3=x+f(dx[i],dx[i+1]);
        int y3=y+f(dy[i],dy[i+1]);
        if(mapp[x1][y1]=='.'&&mapp[x2][y2]=='.'&&mapp[x3][y3]=='.')
        {
            mapp[x][y]='.';
            for(int nx=x-1;nx<=x+1;nx++)  //开始把'.'感染开来
                for(int ny=y-1;ny<=y+1;ny++)
                    dfs(nx,ny);
            return ;
        }
    }
}
int main()
{
    scanf("%d%d",&r,&c);
    for(int i=1;i<=r;i++)
        scanf("%s",mapp[i]+1);
    for(int i=1;i<=r;i++)
        for(int j=1;j<=c;j++)
            dfs(i,j);
    for(int i=1;i<=r;i++)
        printf("%s\n",mapp[i]+1);
    return 0;
}
