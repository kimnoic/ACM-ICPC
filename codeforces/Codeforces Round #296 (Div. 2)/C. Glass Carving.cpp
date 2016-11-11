#include <iostream>
#include <stdio.h>
#include <vector>
#include <queue>
#include <string.h>
#include <map>
#include <stdlib.h>
#include <algorithm>
#include <math.h>
#include <set>
using namespace std;
#define INF 0x3ffffffff
#define Max 200010
long long v,h,n;
char t;
long long hn[Max],vn[Max];
long long tm;
set<int> ve,ho;
set<int>::iterator i,j;
void cut(set<int> &s,long long a[],long long p)
{
	s.insert(p);
	i=j=s.find(p);
	--i,++j,--a[*j-*i];
	++a[p-*i],++a[*j-p];
}
int main()
{
	cin>>v>>h>>n;
	memset(hn,0,sizeof(hn));
	memset(vn,0,sizeof(vn));
	ve.clear();ho.clear();
	ve.insert(0);ve.insert(v);
	ho.insert(0);ho.insert(h);
	hn[h]++;vn[v]++;
	long long hh=h,vv=v;
	while(n--)
	{
		cin>>t>>tm;
		if(t=='V')
			cut(ve,vn,tm);
		else
			cut(ho,hn,tm);
		while(!vn[vv])vv--;
		while(!hn[hh])hh--;
		cout<<vv*hh<<endl;

	}
	return 0;
}
