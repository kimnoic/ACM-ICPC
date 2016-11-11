#include <iostream>
#include <string.h>
#define Max 2333
#define INF 1000000
using namespace std;
int n,m;
char t[Max][10];
int edge[Max][Max];
int lowcost[Max];
int nearvex[Max];
void prim(int u0)
{
	int sumweight = 0;
	for(int i=1;i<=n;i++)
	{
		lowcost[i]=edge[u0][i];
		nearvex[i]=u0;
	}
	nearvex[u0]=-1;
	for(int i=1;i<n;i++)
	{
		int min=INF;
		int v=-1;
		for(int j=1;j<=n;j++)
		{
			if(nearvex[j]!=-1&&lowcost[j]<min)
			{
				v=j;min=lowcost[j];
			}
		}
		if(v!=-1)
		{
			nearvex[v]=-1;//²åÈëÒ»Ìõ±ß
			sumweight+=lowcost[v];
			for(int j=1;j<=n;j++)
			{
				if(nearvex[j]!=-1&&edge[v][j]<lowcost[j])
				{
					lowcost[j]=edge[v][j];
					nearvex[j]=v;
				}
			}
		}
	}
	cout<<"The highest possible quality is 1/"<<sumweight<<"."<<endl;
}
int main()
{
	while(cin>>n)
	{
		if(n==0) break;
		memset(edge,0,sizeof(edge));
		for(int i=1;i<=n;i++) cin>>t[i];
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i!=j)
				{
					int y=0;
					m++;
					for(int k=0;k<7;k++)
					{
						if(t[i][k]!=t[j][k]) y++;
					}
					edge[i][j]=y;
				}
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
			{
				if(i==j) edge[i][j]=0;
				else if(edge[i][j]==0) edge[i][j]=INF;
			}
		}
		prim(1);
	}
	return 0;
}
