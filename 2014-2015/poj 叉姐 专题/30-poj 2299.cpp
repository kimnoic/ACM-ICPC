#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <queue>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <string.h>
#include <math.h>
#include <stdlib.h>
using namespace std;
#define Max 500010
int lowbit(int a)
{
	return a&(-a);
}
int c[Max],v[Max];
struct pt
{
	int pos,val;
}e[Max];
long long n,sum;
bool cmp(pt a, pt b)
{
	return a.val<b.val;
}
void update(int x)
{
	while(x<=n)
	{
		c[x]+=1;
		x+=lowbit(x);
	}
	return ;
}
int getsum(int x)
{
	int res=0;
	while(x>0)
	{
		res+=c[x];
		x-=lowbit(x);
	}
	return res;
}
int main()
{
	while(cin>>n)
	{
		if(n==0) break;
		for(int i=1;i<=n;i++)
		{
			cin>>e[i].val;
			e[i].pos=i;
		}
		sum=0;
		sort(e+1,e+n+1,cmp);
		memset(c,0,sizeof(c));
		for(int i=1;i<=n;i++) v[e[i].pos]=i;
		for(int i=1;i<=n;i++)
		{
			update(v[i]);
			sum+=i-getsum(v[i]);
		}
		cout<<sum<<endl;
	}
	return 0;
}
