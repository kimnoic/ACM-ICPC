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
long long c,hr,hb,wr,wb;
bool flag=true;
long long maxx,minn,res;
int main()
{
	cin>>c>>hr>>hb>>wr>>wb;
	if(hb*wr<hr*wb)
	{
		long long tmp=hr;
		hr=hb;
		hb=tmp;
		tmp=wr;wr=wb;wb=tmp;
	}
		int lr=c/wr;
		int lb=c/wb;
		for(int i=0;i<=lb;i++)
		{
			int j=(c-i*wb)/wr;
			maxx=max(maxx,i*hb+j*hr);
			if(maxx==c) break;
		}
	cout<<maxx;
	return 0;
}
