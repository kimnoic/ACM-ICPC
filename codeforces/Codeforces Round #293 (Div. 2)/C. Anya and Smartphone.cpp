#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <map>
#include <algorithm>
#include <string.h>
#include <stdlib.h>
#include <math.h>
using namespace std;
#define Max 233333
long long pos[Max];
long long val[Max];
long long n,m,k,t,sum=0,po,va,tmp;
int main()
{
	cin>>n>>m>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>pos[i];
		val[pos[i]]=i;
	}
	sum=0;
	for(int i=1;i<=m;i++)
	{
		cin>>t;
		if(val[t]==1)
		{
			sum+=1;
			continue;
		}
		sum+=val[t]/k;
		if(val[t]%k!=0) sum+=1;
		po=val[t]-1;
		va=pos[po];

		val[va]+=1;
		val[t]-=1;

		tmp=pos[val[va]];
		pos[val[va]]=pos[val[t]];
		pos[val[t]]=tmp;
	}
	cout<<sum;
	return 0;
}
