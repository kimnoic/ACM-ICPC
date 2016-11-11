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
int a,b;
int main()
{
	cin>>a>>b;
	int minn=min(a,b);
	int maxx=max(a,b);
	if(maxx>=2*minn) cout<<minn;
	else
	{
		int sum=maxx-minn;
		minn-=sum;
		sum+=2*(minn/3);
		if(minn%3==2) sum+=1;
		cout<<sum;
	}
	return 0;
}
