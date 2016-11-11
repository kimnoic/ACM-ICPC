#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <stdlib.h>
#include <map>
#include <set>
#include <vector>
#include <queue>
#include <stack>
#include <math.h>
#include <string.h>
using namespace std;
#define Max 25000010
short hash[Max];
int cal(int a)
{
	return a*a*a;
}
int main()
{
	int a,b,c,d,e;
	cin>>a>>b>>c>>d>>e;
	for(int i=-50;i<=50;i++)
	{
		if(i==0 ) continue;
		for(int j=-50;j<=50;j++)
		{
			if(j==0) continue;
			int k=a*cal(i)+b*cal(j);
			k+=12500000;
			hash[k]++;
		}
	}
	int res=0;
	for(int i=-50;i<=50;i++)
	{
		if(i==0) continue;
		for(int j=-50;j<=50;j++)
		{
			if(j==0) continue;
			for(int k=-50;k<=50;k++)
			{
				if(k==0) continue;
				int kk=(-c)*cal(i)+(-d)*cal(j)+(-e)*cal(k);
				kk+=12500000;
				if(kk>=0&&kk<=25000000)
				res+=hash[kk];
			}
		}
	}
	cout<<res;
	return 0;
}
