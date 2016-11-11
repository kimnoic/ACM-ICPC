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
long long a,b,n,l,t,m;
long long getr(int t)
{
	return a+(t-1)*b;
}
long long getsum(int t)
{
	return (getr(t)+getr(l))*(t-l+1)/2;
}
int main()
{
	cin>>a>>b>>n;
	for(int k=1;k<=n;k++)
	{
		cin>>l>>t>>m;
		if(getr(l)>t) cout<<"-1"<<endl;
		else
		{
			int re=l,li=(t-a)/b+1,mid=(re+li)/2;
			while(re<=li)
			{
				mid=(re+li)/2;
				if(getsum(mid)>t*m) li=mid-1;
				else re=mid+1;
			}
			cout<<re-1<<endl;
		}
	}
	return 0;
}
