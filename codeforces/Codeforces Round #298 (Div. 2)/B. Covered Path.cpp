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
int v1,v2,t,d,res=0;
int main()
{
	cin>>v1>>v2>>t>>d;
	while(v1<v2)
	{
		res+=v1;
		v1+=d;
		t--;
	}
	while(t!=1)
	{
		if(v1>v2)
		{
			res+=v2;
			v2+=d;
			t--;
		}
		else
		{
			res+=v1;
			v1+=d;
			t--;
		}
	}
	v1-=d;v2-=d;
	res+=min(v1,v2)+d;
	cout<<res;
	return 0;
}
