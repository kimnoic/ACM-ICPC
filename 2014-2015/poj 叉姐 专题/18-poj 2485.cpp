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
			if(sumweight<lowcost[v])
			sumweight=lowcost[v];
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
	cout<<sumweight<<endl;
}
int main()
{
	int T;
	cin>>T;
	while(T--)
	{
		cin>>n;
		memset(edge,0,sizeof(edge));
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
			cin>>edge[i][j];
		prim(1);
	}
	return 0;
}
