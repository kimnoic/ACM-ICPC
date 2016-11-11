#include <iostream>
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
#include <stack>
#include <stdlib.h>
#include <math.h>
#include <set>
#include <map>
using namespace std;
#define Max 1200010
#define MOD 1200007
struct Node
{
	int num[6];
	int next;
};
Node node[Max];
int cur=0;
int hashtable[MOD];
void init()
{
	for(int i=0;i<=MOD;i++)
	{
		hashtable[i]=-1;
	}
}
int gethash(int *num)
{
	int hash=0;
	for(int i=0;i<6;i++)
	{
		hash+=num[i];
	}
	hash%=MOD;
	return hash;
}
bool cmp(int *num1 ,int *num2)
{
	for(int i=0;i<6;i++)
	{
		if(num1[i]!=num2[i]) return false;
	}
	return true;
}
void inserthash(int *num,int h)
{
	for(int i=0;i<6;i++)
	{
		node[cur].num[i]=num[i];
	}
	node[cur].next=hashtable[h];
	hashtable[h]=cur;
	cur++;
}
bool searchhash(int *num)
{
	int h=gethash(num);
	int next=hashtable[h];
	while(next!=-1)
	{
		if(cmp(num,node[next].num)) return true;
		next=node[next].next;
	}
	inserthash(num,h);
	return false;
}

int main()
{
	int num[2][12];
	int n;
	int flag=0;
	init();
	cin>>n;
	while(n--)
	{
		for(int i=0;i<6;i++)
		{
			scanf("%d",&num[0][i]);
			num[0][i+6]=num[0][i];
		}
		if(flag) continue;
		for(int i=0;i<6;i++)
		{
			num[1][i+6]=num[1][i]=num[0][5-i];
		}
		for(int i=0;i<6;i++)
		{
			if(searchhash(num[0]+i)||searchhash(num[1]+i)) {flag=1;break;}
		}
	}
	if(flag) cout<<"Twin snowflakes found.";
	else cout<<"No two snowflakes are alike.";
	return 0;
}
