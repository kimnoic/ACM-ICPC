#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <set>
#include <queue>
#include <math.h>
#include <vector>
#include <map>
using namespace std;
#define INF 0x3ffffffff
long long n,d[200010];
long long sum;long long t;
long long b[200010];
long long minn,maxx,tsum;
int main()
{
	cin>>n>>sum;
	for(int i=1;i<=n;i++)
	{
		cin>>d[i];
		t+=d[i];
	}
	minn=n-1;
	int tm=0;
	for(int i=1;i<=n;i++)
	{
		tsum=t-d[i];
		maxx=min(d[i],sum-(n-1));
		minn=sum-tsum;
		if(minn<=0) minn=1;
		cout<<d[i]-(maxx-minn+1)<<" ";
	}
	return 0;
}
