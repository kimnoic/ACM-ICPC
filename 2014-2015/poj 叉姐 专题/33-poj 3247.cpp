#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <math.h>
#include <string.h>
#include <stdlib.h>
#include <vector>
#include <stack>
#include <queue>
#include <set>
#include <map>
using namespace std;
#define Max 100010
#define MOD 100007
struct Node
{
	int pos;
	int next;
};
Node node[Max];
int hashtable[Max];
int cur,n,k,ans,temp;
int c[Max][32];
bool check(int x)
{
	for(int i=0;i<k-1;i++)
	{
		if(c[x][i]!=c[x][i+1]) return false;
	}
	return true;
}
void init()
{
	cin>>n>>k;
	ans=0;
	for(int i=0;i<MOD;i++) hashtable[i]=-1;
	for(int i=0;i<n;i++)
	{
		scanf("%d",&temp);
		for(int j=0;j<k;j++)
		{
			c[i][j]=temp&1;
			temp/=2;
		}
	}
	for(int j=0;j<k;j++)
	{
		for(int i=1;i<n;i++) c[i][j]+=c[i-1][j];
	}
	for(int i=n-1;i>=0;i--)
	{
		if(check(i)) {ans=i+1;break;}
	}
	for(int j=0;j<k;j++)
	{
		for(int i=0;i<n;i++) c[i][j]-=c[i][k-1];
	}
	cur=0;
}
bool cmp(int a,int b)
{
	for(int i=0;i<k;i++)
	{
		if(c[a][i]!=c[b][i]) return false;
	}
	return true;
}
unsigned int gethash(int x)
{
	unsigned int hash=0;
	for(int i=0;i<k;i++)
	{
		hash+=c[x][i]*(i+1);		//cout<<x<<" "<<i<<" "<<c[x][i]<<endl;
	}
	return (hash%MOD);
}
void searchhash(int x)
{
	int h=gethash(x);
	int next=hashtable[h];
	while(next!=-1)
	{

		if(cmp(node[next].pos,x))
		{
			if(x-node[next].pos>ans) ans=x-node[next].pos;
			return ;
		}
		next=node[next].next;
	}
	node[cur].pos=x;
	node[cur].next=hashtable[h];
	hashtable[h]=cur;
	cur++;
}
int main()
{
	init();
	for(int i=0;i<n;i++) {searchhash(i);}
	cout<<ans<<endl;
	return 0;
}
