#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <fstream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
using namespace std;
#define Maxn 1010
#define Maxm 32
double f[Maxn][Maxm];
double g[Maxn][Maxm][Maxm];
int m,t,n;
int main()
{
	while(cin>>m>>t>>n)
	{
		if(m==0&&t==0&&n==0) break;
		for(int i=1;i<=t;i++)
		{
			for(int j=1;j<=m;j++)
			{
				cin>>f[i][j];
			}
		}
		memset(g,0,sizeof(g));
		for(int i=1;i<=t;i++)
		{
			g[i][0][0]=1;
			for(int j=1;j<=m;j++)
			{
				g[i][j][0]=g[i][j-1][0]*(1-f[i][j]);
				for(int k=1;k<=j;k++)
				{
					g[i][j][k]=g[i][j-1][k-1]*f[i][j]+g[i][j-1][k]*(1-f[i][j]);
				}
			}
		}
		double res=1;
		for(int i=1;i<=t;i++)
		{
			res*=(1-g[i][m][0]);
		}
		double temp=1;
		for(int i=1;i<=t;i++)
		{
			double cnt=0;
			for(int j=1;j<n;j++)
			{
				cnt+=g[i][m][j];
			}
			temp*=cnt;
		}
		printf("%.3lf\n",res-temp);
		//cout<<res-temp<<endl;
	}
	return 0;
}
