#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <map>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
using namespace std;
#define INF 0x3ffffffff
long long a,b;
int main()
{
	cin>>a>>b;
	long long sum=0;
	long long maxx=max(a,b);
	long long minn=min(a,b);
	a=maxx;
	b=minn;
	while(a!=0&&b!=0)
	{
		sum+=a/b;
		a%=b;
		maxx=a;
		minn=b;
		a=max(maxx,minn);
		b=min(maxx,minn);
	}
	cout<<sum;
	return 0;
}
