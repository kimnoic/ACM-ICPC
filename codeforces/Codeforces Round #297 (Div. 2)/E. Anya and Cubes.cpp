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
#define INF 0x3ffffffff
#define N 30
long long f[N];
int num[N];
int n,k;
long long s;
map<int,long long>mp[N];
long long res=0;
void dfs_1(int a,int cnt,long long sum)
{
	if(cnt>k||sum>s) return ;
	if(a==n/2)
	{
		mp[cnt][sum]++;
		return ;
	}
	dfs_1(a+1,cnt,sum);
	dfs_1(a+1,cnt,sum+num[a]);
	if(num[a]<=18)
	{
		dfs_1(a+1,cnt+1,sum+f[num[a]]);
	}
}
void dfs_2(int a,int cnt,long long sum)
{
	if(cnt>k||sum>s) return ;
	if(a==n)
	{
		for(int i=0;i+cnt<=k;i++)
		{
			if(mp[i].count(s-sum))
			{
				res+=mp[i][s-sum];
			}
		}
		return ;
	}
	dfs_2(a+1,cnt,sum);
	dfs_2(a+1,cnt,sum+num[a]);
	if(num[a]<=18)
	{
		dfs_2(a+1,cnt+1,sum+f[num[a]]);
	}
}
int main()
{
	f[0]=1;
	for(int i=1;i<=18;i++) f[i]=f[i-1]*i;
	cin>>n>>k>>s;
	for(int i=0;i<n;i++)
		cin>>num[i];
	dfs_1(0,0,0);
	res=0;
	dfs_2(n/2,0,0);
	cout<<res;
	return 0;
}

