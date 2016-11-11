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
#define Max 200010
int f[Max]={};
string t;
int n;
int main()
{
	cin>>t;
	cin>>n;
	int len=t.size();
	int d;
	for(int i=1;i<=n;i++)
	{
		cin>>d;
		d--;
		f[d]++;
	}
	for(int i=i;i<len/2;i++)
		f[i]+=f[i-1];
	for(int i=0;i<len/2;i++)
		if(f[i]%2==1)
	{
		char tm=t[i];
		t[i]=t[len-i-1];
		t[len-i-1]=tm;
	}
	cout<<t;
	return 0;
}
